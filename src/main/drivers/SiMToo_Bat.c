/*
 * This file is part of INAV Project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Alternatively, the contents of this file may be used under the terms
 * of the GNU General Public License Version 3, as described below:
 *
 * This file is free software: you may copy, redistribute and/or modify
 * it under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see http://www.gnu.org/licenses/.
 */


#include <stdbool.h>
#include <stdint.h>
#include "platform.h"

#if defined(USE_007PRO_BATT_SENSOR)

#include "drivers/bus.h"
#include "drivers/bus_i2c.h"
#include "fc/config.h"
#include "drivers/SiMToo_Bat.h"

static uint16_t SiMTooVbat = 0;
static uint16_t SiMTooAmerperage = 0;
static busDevice_t *SiMTooBat_dev = 0;

static bool SiMTooBat_Read(uint8_t reg, uint8_t *buf, uint8_t len)
{
    
    const busSpeed_e speed_map[] = {BUS_SPEED_FAST,             // I2C_SPEED_400KHZ
                                    BUS_SPEED_ULTRAFAST,        // I2C_SPEED_800KHZ
                                    BUS_SPEED_STANDARD,         // I2C_SPEED_100KHZ
                                    BUS_SPEED_INITIALIZATION,   // I2C_SPEED_200KHZ
                                    BUS_SPEED_SLOW};            // I2C_SPEED_40KHZ      

    busSetSpeed(SiMTooBat_dev, speed_map[I2C_SPEED_40KHZ]);

    bool ack = busReadBuf(SiMTooBat_dev, reg, buf, len);
    
    busSetSpeed(SiMTooBat_dev, speed_map[systemConfig()->i2c_speed]);
    
    return ack;
}

void SiMTooBattSensorVbat_Updata(void)
{
    static uint8_t data[2] = {0};
    if (SiMTooBat_Read(SIMTOO_BAT_VBAT_REG, data, 2))
    {
        SiMTooVbat = (((uint16_t)data[1]) << 8 | data[0]) / 10;
    }
}

void SiMTooBattSensorAmperage_Updata(void)
{

}

uint16_t SiMTooBattSensorGetVBat(void)
{
    return SiMTooVbat;    // 精确到0.01V
}

uint16_t SiMTooBattSensorGetAmerperage(void)
{
    return SiMTooAmerperage;    // 精确到 0.01A
}

void SiMTooBat_Init(void)
{
    SiMTooBat_dev = busDeviceInit(BUSTYPE_I2C, DEVHW_007PRO_BAT, 0, OWNER_BAT);
}
#endif