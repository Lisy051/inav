/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define USE_TARGET_CONFIG

#define TARGET_BOARD_IDENTIFIER "XTF4"
#define USBD_PRODUCT_STRING "XT200 F4"

// ******** Board LEDs  **********************
#define LED0                    PC14

// ******* Beeper ***********
#define BEEPER                  PC15
#define BEEPER_INVERTED

// ******* GYRO and ACC ********
#define USE_EXTI
#define MPU6500_EXTI_PIN        PC13

#define USE_MPU_DATA_READY_SIGNAL

#define USE_IMU_MPU6500
#define IMU_MPU6500_ALIGN               CW0_DEG
#define MPU6500_SPI_BUS                 BUS_SPI1
#define MPU6500_CS_PIN                  PA4

//*********** Magnetometer / Compass *************
#define USE_I2C
#define USE_I2C_DEVICE_2
#define USE_MAG
#define MAG_I2C_BUS                     BUS_I2C2
#define USE_MAG_IST8310

// *************** Baro **************************
#define USE_BARO

#define USE_BARO_BMP280
#define USE_BARO_SPI_BMP280
#define BMP280_SPI_BUS                 BUS_SPI2
#define BMP280_CS_PIN                  PB12

#define USE_BARO_SPL06
#define USE_BARO_SPI_SPL06
#define SPL06_SPI_BUS                  BUS_SPI2
#define SPL06_CS_PIN                   PB12

// ******* SERIAL ********
#define USE_VCP
#define VBUS_SENSING_PIN                PA9
#define VBUS_SENSING_ENABLED

#define USE_UART2
#define UART2_TX_PIN                    PA2
#define UART2_RX_PIN                    PA3

#define USE_UART4
#define UART4_TX_PIN                    PA0
#define UART4_RX_PIN                    PA1

#define USE_UART6
#define UART6_TX_PIN                    PC6
#define UART6_RX_PIN                    PC7

#define USE_SOFTSERIAL1
#define SOFTSERIAL_1_TX_PIN             PA8
#define SOFTSERIAL_1_RX_PIN             PA8

#define SERIAL_PORT_COUNT               5

// ******* SPI ********
#define USE_SPI

#define USE_SPI_DEVICE_1
#define SPI1_NSS_PIN                    PA4
#define SPI1_SCK_PIN                    PA5
#define SPI1_MISO_PIN                   PA6
#define SPI1_MOSI_PIN                   PA7

#define USE_SPI_DEVICE_2
#define SPI2_NSS_PIN                    PB12
#define SPI2_SCK_PIN                    PB13
#define SPI2_MISO_PIN                   PB14
#define SPI2_MOSI_PIN                   PB15

//******* FLASH ********
#define USE_SDCARD
#define USE_SDCARD_SDIO
#define SDCARD_SDIO_DMA         DMA_TAG(2,3,4)
#define SDCARD_SDIO_4BIT
#define ENABLE_BLACKBOX_LOGGING_ON_SDCARD_BY_DEFAULT

// ******* ADC ********
#define USE_ADC
#define USE_007PRO_BATT_SENSOR
#define BAT_007PRO_I2C_BUS              BUS_I2C2

#define ADC_CHANNEL_1_PIN               PC1
#define ADC_CHANNEL_2_PIN               PC2
#define ADC_CHANNEL_3_PIN               PC3

#define VBAT_ADC_CHANNEL                ADC_CHN_2
#define RSSI_ADC_CHANNEL                ADC_CHN_3
#define CURRENT_METER_ADC_CHANNEL       ADC_CHN_1

#define VBAT_SCALE_DEFAULT              1100

// ******* FEATURES ********
#define SENSORS_SET             (SENSOR_ACC|SENSOR_MAG|SENSOR_BARO)
#define DEFAULT_FEATURES        (FEATURE_TX_PROF_SEL | FEATURE_BLACKBOX | FEATURE_SOFTSERIAL)

// Number of available PWM outputs
#define MAX_PWM_OUTPUT_PORTS    4
#define TARGET_MOTOR_COUNT      4

#define TARGET_IO_PORTA         0xffff
#define TARGET_IO_PORTB         0xffff
#define TARGET_IO_PORTC         0xffff
#define TARGET_IO_PORTD         0xffff

// ESC-related features
#define USE_DSHOT
#define USE_SERIALSHOT
#define USE_ESC_SENSOR
#define USE_SERIAL_4WAY_BLHELI_INTERFACE