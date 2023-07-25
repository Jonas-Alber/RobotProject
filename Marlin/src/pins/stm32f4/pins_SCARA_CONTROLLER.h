/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include "env_validate.h"

#if NOT_TARGET(STM32F4, STM32F4xx)
  #error "Oops! Select an STM32F4 board in 'Tools > Board.'"
#endif

#ifndef BOARD_INFO_NAME
  #define BOARD_INFO_NAME "BOARD_SCARA_CONTROLLER"
#endif

#ifndef DEFAULT_MACHINE_NAME
  #define DEFAULT_MACHINE_NAME BOARD_INFO_NAME
#endif

//#define I2C_EEPROM
//#define E2END                 0x7F  

#define I2C_SCL_PIN                           PF1
#define I2C_SDA_PIN                           PF0

//
// Limit Switches
//
#define X_MIN_PIN                             PE1
//#define X_MAX_PIN                           PF8
#define Y_MIN_PIN                             PE0
//#define Y_MAX_PIN                           PF6
#define Z_MIN_PIN                             PB4
//#define Z_MAX_PIN                           PF5



//
// Steppers
//

#define X_CS_PIN                            PE3
#define Y_CS_PIN                            PG10
#define Z_CS_PIN                            PB8
#define E0_CS_PIN                           PE13

#define TMC_SW_MOSI                         PB15
#define TMC_SW_MISO                         PB14
#define TMC_SW_SCK                          PB13

#define X_STEP_PIN                          PE2
#define X_DIR_PIN                           PE4
#define X_ENABLE_PIN                        PG15

#define Y_STEP_PIN                          PD4
#define Y_DIR_PIN                           PD11
#define Y_ENABLE_PIN                        PD3

#define Z_STEP_PIN                          PG5
#define Z_DIR_PIN                           PG4
#define Z_ENABLE_PIN                        PD14

#define E0_STEP_PIN                         PB12
#define E0_DIR_PIN                          PE7
#define E0_ENABLE_PIN                       PC4


//
// Temperature Sensors
//
#define TEMP_0_PIN                          PC0   // T0
#define TEMP_1_PIN                          PC1   // T1
#define TEMP_BED_PIN                        PC2   // TB

#ifndef TEMP_CHAMBER_PIN
  #define TEMP_CHAMBER_PIN                  PC3   // TC
#endif

//
// Heaters / Fans
//
#define HEATER_0_PIN                        PG0   // Heater0
#define HEATER_1_PIN                        PG1   // Heater1
#define HEATER_BED_PIN                      PF15   // Hotbed

#define FAN_PIN                             -1   // Fan0
#define FAN1_PIN                            -1  // Fan1
#define FAN2_PIN                            -1  // Fan2
#define FAN3_PIN                            -1  // Fan3

//
// Misc. Functions
//
#define LED_PIN                             -1
//#define LED_PIN                           PA7
#define KILL_PIN                            -1

//
// Onboard SD support
//
#define SDIO_D0_PIN                         PC8
#define SDIO_CK_PIN                         PC12
#define SDIO_CMD_PIN                        PD2
#define SD_DETECT_PIN                       PG6

#define USB_OTG_FS_DP                       PA12
#define USB_OTG_FS_DM                       PA11

#ifndef SDCARD_CONNECTION
  #define SDCARD_CONNECTION              ONBOARD
#endif

#if SD_CONNECTION_IS(ONBOARD)
  #define SDIO_SUPPORT                            // Use SDIO for onboard SD

  #ifndef SDIO_SUPPORT
    #define SOFTWARE_SPI                          // Use soft SPI for onboard SD
    #define SDSS                     SDIO_D3_PIN
    #define SCK_PIN                  SDIO_CK_PIN
    #define MISO_PIN                 SDIO_D0_PIN
    #define MOSI_PIN                SDIO_CMD_PIN
  #endif
#endif
