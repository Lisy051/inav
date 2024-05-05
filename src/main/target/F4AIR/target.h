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

#define TARGET_BOARD_IDENTIFIER "F4AIR"
#define USBD_PRODUCT_STRING "F4AIR Ly"

// ******** Board LEDs  **********************
#define LED0                    PC14
#define LED1                    PC15

// ******* Beeper ***********
#define BEEPER                  PC13
#define BEEPER_INVERTED

// ******* GYRO and ACC ********
#define USE_EXTI
#define MPU6500_EXTI_PIN        PC4

#define USE_MPU_DATA_READY_SIGNAL

#define USE_IMU_MPU6500
#define IMU_MPU6500_ALIGN               CW270_DEG_FLIP
#define MPU6500_SPI_BUS                 BUS_SPI3
#define MPU6500_CS_PIN                  PA15

//*********** Magnetometer / Compass *************
#define USE_MAG

#ifdef F4AIRV100
#define USE_MAG_AK8975
#define AK8975_SPI_BUS                  BUS_SPI3
#define AK8975_CS_PIN                   PC10

#else
#define USE_MAG
#define MAG_I2C_BUS                     BUS_I2C1
#define USE_MAG_IST8310

#endif

// *************** Baro **************************
#define USE_BARO
#define USE_BARO_SPL06

#ifdef F4AIRV100
#define USE_BARO_SPI_SPL06
#define SPL06_SPI_BUS                  BUS_SPI3
#define SPL06_CS_PIN                   PC11

#else
#define BARO_I2C_BUS                   BUS_I2C1
#endif

// ******* SERIAL ********
#define USE_VCP
#define VBUS_SENSING_PIN                PA8
#define VBUS_SENSING_ENABLED

#define USE_UART1
#define UART1_TX_PIN                    PA9
#define UART1_RX_PIN                    PA10

#define USE_UART2
#define UART2_TX_PIN                    PA2
#define UART2_RX_PIN                    NONE

#define USE_UART3
#define UART3_TX_PIN                    PB10
#define UART3_RX_PIN                    PB11

#define USE_UART4
#define UART4_TX_PIN                    PA0
#define UART4_RX_PIN                    PA1

#define USE_UART5
#define UART5_TX_PIN                    PC12
#define UART5_RX_PIN                    PD2

#define SERIAL_PORT_COUNT               6

// ******* SPI ********
#define USE_SPI

#define USE_SPI_DEVICE_1
#define SPI1_NSS_PIN                    PA4
#define SPI1_SCK_PIN                    PA5
#define SPI1_MISO_PIN                   PA6
#define SPI1_MOSI_PIN                   PA7

#define USE_SPI_DEVICE_3
#define SPI3_SCK_PIN                    PB3
#define SPI3_MISO_PIN                   PB4
#define SPI3_MOSI_PIN                   PB5

// ******* I2C ********
#define USE_I2C

#define USE_I2C_DEVICE_1
#define I2C1_SCL                PB6
#define I2C1_SDA                PB7

//******* FLASH ********
#define USE_FLASHFS
#define USE_FLASH_M25P16
#define M25P16_SPI_BUS                  BUS_SPI1
#define M25P16_CS_PIN                   PA4

#define ENABLE_BLACKBOX_LOGGING_ON_SPIFLASH_BY_DEFAULT

// ******* ADC ********
#define USE_ADC

#define ADC_CHANNEL_1_PIN               PC5
#define ADC_CHANNEL_2_PIN               PC2
#define ADC_CHANNEL_3_PIN               PC3

#define VBAT_ADC_CHANNEL                ADC_CHN_1
#define RSSI_ADC_CHANNEL                ADC_CHN_2
#define CURRENT_METER_ADC_CHANNEL       ADC_CHN_3

#define VBAT_SCALE_DEFAULT              920

// ******* Rangefinder ********
#define USE_RANGEFINDER
#define USE_RANGEFINDER_RCWL1605_I2C
#define RCWL1605_I2C_BUS                BUS_I2C1


// ******* FEATURES ********
#define SENSORS_SET             (SENSOR_ACC|SENSOR_MAG|SENSOR_BARO)
#define DEFAULT_FEATURES        (FEATURE_TX_PROF_SEL | FEATURE_BLACKBOX | FEATURE_SOFTSERIAL)

// Number of available PWM outputs
#define MAX_PWM_OUTPUT_PORTS    8
#define TARGET_MOTOR_COUNT      8

#define TARGET_IO_PORTA         0xffff
#define TARGET_IO_PORTB         0xffff
#define TARGET_IO_PORTC         0xffff
#define TARGET_IO_PORTD         0xffff

// ESC-related features
#define USE_DSHOT
#define USE_SERIALSHOT
#define USE_ESC_SENSOR
#define USE_SERIAL_4WAY_BLHELI_INTERFACE