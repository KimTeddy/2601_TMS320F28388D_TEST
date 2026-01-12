/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef BOARD_H
#define BOARD_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//
// Included Files
//

#include "driverlib.h"
#include "device.h"

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************

//
// EPWM1 -> EPWM1_U Pinmux
//
//
// EPWM1A - GPIO Settings
//
#define GPIO_PIN_EPWM1A 0
#define EPWM1_U_EPWMA_GPIO 0
#define EPWM1_U_EPWMA_PIN_CONFIG GPIO_0_EPWM1A
//
// EPWM1B - GPIO Settings
//
#define GPIO_PIN_EPWM1B 1
#define EPWM1_U_EPWMB_GPIO 1
#define EPWM1_U_EPWMB_PIN_CONFIG GPIO_1_EPWM1B
//
// GPIO61 - GPIO Settings
//
#define LED1_61_GPIO_PIN_CONFIG GPIO_61_GPIO61
//
// GPIO62 - GPIO Settings
//
#define LED2_62_GPIO_PIN_CONFIG GPIO_62_GPIO62
//
// GPIO145 - GPIO Settings
//
#define LED3_145_GPIO_PIN_CONFIG GPIO_145_GPIO145
//
// GPIO146 - GPIO Settings
//
#define LED4_146_GPIO_PIN_CONFIG GPIO_146_GPIO146

//*****************************************************************************
//
// CPUTIMER Configurations
//
//*****************************************************************************
#define myCPUTIMER0_BASE CPUTIMER0_BASE
void myCPUTIMER0_init();

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
#define EPWM1_U_BASE EPWM1_BASE
#define EPWM1_U_TBPRD 2000
#define EPWM1_U_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define EPWM1_U_TBPHS 0
#define EPWM1_U_CMPA 500
#define EPWM1_U_CMPB 1500
#define EPWM1_U_CMPC 0
#define EPWM1_U_CMPD 0
#define EPWM1_U_DBRED 0
#define EPWM1_U_DBFED 0
#define EPWM1_U_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define EPWM1_U_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define EPWM1_U_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
#define LED1_61 61
void LED1_61_init();
#define LED2_62 62
void LED2_62_init();
#define LED3_145 145
void LED3_145_init();
#define LED4_146 146
void LED4_146_init();

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************

// Interrupt Settings for INT_myCPUTIMER0
// ISR need to be defined for the registered interrupts
#define INT_myCPUTIMER0 INT_TIMER0
#define INT_myCPUTIMER0_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void INT_myCPUTIMER0_ISR(void);

//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void	Board_init();
void	CPUTIMER_init();
void	EPWM_init();
void	GPIO_init();
void	INTERRUPT_init();
void	SYNC_init();
void	PinMux_init();

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // end of BOARD_H definition
