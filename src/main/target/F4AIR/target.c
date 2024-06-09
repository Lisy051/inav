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

#include <stdint.h>

#include "platform.h"
#include "drivers/io.h"
#include "drivers/timer.h"
#include "drivers/timer_def.h"
#include "drivers/pwm_mapping.h"
#include "drivers/bus.h"

timerHardware_t timerHardware[] = {
#if defined (F4AIRV100) || defined(F4AIRV150) || defined(F4AIRV200)
    DEF_TIM(TIM8,   CH1,  PC6,      TIM_USE_OUTPUT_AUTO,  0, 1 ),   // S1 DMA2 CH2
    DEF_TIM(TIM8,   CH2,  PC7,      TIM_USE_OUTPUT_AUTO,  0, 1 ),   // S2 DMA2 CH3
    DEF_TIM(TIM8,   CH3,  PC8,      TIM_USE_OUTPUT_AUTO,  0, 1 ),   // S3 DMA2 CH4
    DEF_TIM(TIM8,   CH4,  PC9,      TIM_USE_OUTPUT_AUTO,  0, 0 ),   // S4 DMA2 CH7

#if defined (F4AIRV100) || defined(F4AIRV150)
    DEF_TIM(TIM12,  CH1,  PB14,     TIM_USE_OUTPUT_AUTO,  0, 0 ),   // S5 NO DMA
    DEF_TIM(TIM12,  CH2,  PB15,     TIM_USE_OUTPUT_AUTO,  0, 0 ),   // S6 NO DMA
#else
    DEF_TIM(TIM4,   CH1,  PB6,      TIM_USE_OUTPUT_AUTO,  0, 0 ),   // S5 DMA1 CH0
    DEF_TIM(TIM4,   CH2,  PB7,      TIM_USE_OUTPUT_AUTO,  0, 0 ),   // S6 DMA1 CH3
#endif
    DEF_TIM(TIM3,   CH3,  PB0,      TIM_USE_OUTPUT_AUTO,  0, 0 ),   // S7 DMA1 CH7
    DEF_TIM(TIM3,   CH4,  PB1,      TIM_USE_OUTPUT_AUTO,  0, 0 ),   // S8 DMA1 CH2

#if defined (F4AIRV200)
    DEF_TIM(TIM2,   CH1,  PA0,      TIM_USE_BEEPER,       0, 0 ),   // BEEPER DMA1 CH5
    DEF_TIM(TIM2,   CH2,  PA1,      TIM_USE_LED,          0, 0 ),   // LED DMA1 CH6
#endif
#else
    DEF_TIM(TMR8,   CH1,  PC6,      TIM_USE_OUTPUT_AUTO,  0, 0 ),   // S1 DMA1 CH0
    DEF_TIM(TMR8,   CH2,  PC7,      TIM_USE_OUTPUT_AUTO,  0, 1 ),   // S2 DMA1 CH1
    DEF_TIM(TMR8,   CH3,  PC8,      TIM_USE_OUTPUT_AUTO,  0, 2 ),   // S3 DMA1 CH2
    DEF_TIM(TMR8,   CH4,  PC9,      TIM_USE_OUTPUT_AUTO,  0, 3 ),   // S4 DMA1 CH3
    
    DEF_TIM(TMR4,   CH1,  PB6,      TIM_USE_OUTPUT_AUTO,  0, 4 ),   // S5 DMA1 CH4
    DEF_TIM(TMR4,   CH2,  PB7,      TIM_USE_OUTPUT_AUTO,  0, 5 ),   // S6 DMA1 CH5
    DEF_TIM(TMR3,   CH4,  PB1,      TIM_USE_OUTPUT_AUTO,  0, 6 ),   // S7 DMA1 CH6
    DEF_TIM(TMR3,   CH3,  PB0,      TIM_USE_OUTPUT_AUTO,  0, 7 ),   // S8 DMA1 CH7
    
    DEF_TIM(TMR2,   CH1,  PA0,      TIM_USE_BEEPER,       0, 8 ),   // BEEPER DMA2 CH0
    DEF_TIM(TMR2,   CH2,  PA1,      TIM_USE_LED,          0, 9 ),   // LED DMA2 CH1
#endif
};

const int timerHardwareCount = sizeof(timerHardware) / sizeof(timerHardware[0]);
