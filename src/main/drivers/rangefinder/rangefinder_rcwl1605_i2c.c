/*
 * This file is part of INAV.
 *
 * INAV is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * INAV is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with INAV.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdbool.h>
#include <stdint.h>

#include "platform.h"

#if defined(USE_RANGEFINDER) && defined(USE_RANGEFINDER_RCWL1605_I2C)

#include "fc/config.h"

#include "build/build_config.h"

#include "drivers/time.h"
#include "drivers/bus_i2c.h"

#include "drivers/rangefinder/rangefinder.h"
#include "drivers/rangefinder/rangefinder_rcwl1605_i2c.h"

#include "build/debug.h"

// RCWL-1605 Ultrasonic Range Sensor
#define RCWL_MAX_RANGE_CM 450
#define RCWL_DETECTION_CONE_DECIDEGREES 900
#define RCWL_DETECTION_CONE_EXTENDED_DECIDEGREES 900
#define RCWL_MIN_PROBE_INTERVAL 50

#define RCWL_I2C_Address 0x57
#define RCWL_I2C_START_CMD  0x01

const busSpeed_e speed_map[] = {BUS_SPEED_FAST,             // I2C_SPEED_400KHZ
                                BUS_SPEED_ULTRAFAST,        // I2C_SPEED_800KHZ
                                BUS_SPEED_STANDARD,         // I2C_SPEED_100KHZ
                                BUS_SPEED_INITIALIZATION,   // I2C_SPEED_200KHZ
                                BUS_SPEED_SLOW};            // I2C_SPEED_40KHZ      

volatile int32_t MeasurementCm = RANGEFINDER_OUT_OF_RANGE;
static int16_t minimumReadingIntervalMs = RCWL_MIN_PROBE_INTERVAL;
static uint32_t timeOfLastMeasurementMs = 0;
static uint8_t RCWL_CMD[1];

static void rcwl1605Init(rangefinderDev_t *rangefinder)
{
    RCWL_CMD[0] = RCWL_I2C_START_CMD;

    busSetSpeed(rangefinder->busDev, speed_map[I2C_SPEED_100KHZ]);

    busWriteBuf(rangefinder->busDev, 0xff, RCWL_CMD, 1);

    busSetSpeed(rangefinder->busDev, speed_map[systemConfig()->i2c_speed]);
}

void rcwl1605Update(rangefinderDev_t *rangefinder)
{
    static uint8_t data[3] = {0};
    static uint8_t zero_cnt = 0;
    bool ack;
    int32_t d = 0;
    const timeMs_t timeNowMs = millis();

    busSetSpeed(rangefinder->busDev, speed_map[I2C_SPEED_100KHZ]);

    ack = busReadBuf(rangefinder->busDev, 0xff, data, 3);

    busSetSpeed(rangefinder->busDev, speed_map[systemConfig()->i2c_speed]);

    if (ack) {
        d = ((uint32_t)data[0] << 16 | (uint32_t)data[1] << 8 | (uint32_t)data[2]);
        d /= 10000;

        if (d > RCWL_MAX_RANGE_CM) {
            MeasurementCm = RANGEFINDER_OUT_OF_RANGE;
        } else {
            if (d == 0) {
                zero_cnt++;
                if (zero_cnt > 9) {
                    zero_cnt = 9;
                    MeasurementCm = RANGEFINDER_HARDWARE_FAILURE;
                }
            } else {
                zero_cnt = 0;
                MeasurementCm = d;
            }
        }
    } else {
        MeasurementCm = RANGEFINDER_HARDWARE_FAILURE;
    }

    if (timeNowMs > timeOfLastMeasurementMs + minimumReadingIntervalMs) {
        // measurement repeat interval should be greater than minimumReadingIntervalMs
        // to avoid interference between connective measurements.
        timeOfLastMeasurementMs = timeNowMs;
        rcwl1605Init(rangefinder);
    }
}

/**
 * Get the distance that was measured by the last pulse, in centimeters.
 */
int32_t rcwl1605GetDistance(rangefinderDev_t *rangefinder)
{
    UNUSED(rangefinder);
    return MeasurementCm;
}

static bool deviceDetect(busDevice_t * busDev)
{
    bool ack;
    for (int retry = 0; retry < 5; retry++) {

        delay(150);

        RCWL_CMD[0] = RCWL_I2C_START_CMD;

        busSetSpeed(busDev, speed_map[I2C_SPEED_100KHZ]);

        ack = busWriteBuf(busDev, 0xff, RCWL_CMD, 1);

        busSetSpeed(busDev, speed_map[systemConfig()->i2c_speed]);
        if (ack) {
            return true;
        }
    };

    return false;
}

bool rcwl1605Detect(rangefinderDev_t *rangefinder)
{
    rangefinder->busDev = busDeviceInit(BUSTYPE_I2C, DEVHW_RCWL1605_I2C, 0, OWNER_RANGEFINDER);
    if (rangefinder->busDev == NULL) {
        return false;
    }

    if (!deviceDetect(rangefinder->busDev)) {
        busDeviceDeInit(rangefinder->busDev);
        return false;
    }

    rangefinder->delayMs = RANGEFINDER_RCWL1605_TASK_PERIOD_MS;
    rangefinder->maxRangeCm = RCWL_MAX_RANGE_CM;
    rangefinder->detectionConeDeciDegrees = RCWL_DETECTION_CONE_DECIDEGREES;
    rangefinder->detectionConeExtendedDeciDegrees = RCWL_DETECTION_CONE_EXTENDED_DECIDEGREES;

    rangefinder->init = &rcwl1605Init;
    rangefinder->update = &rcwl1605Update;
    rangefinder->read = &rcwl1605GetDistance;

    return true;
}
#endif