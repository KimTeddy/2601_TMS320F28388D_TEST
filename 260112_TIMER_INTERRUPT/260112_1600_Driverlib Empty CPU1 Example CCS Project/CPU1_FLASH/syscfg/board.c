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

#include "board.h"

//*****************************************************************************
//
// Board Configurations
// Initializes the rest of the modules. 
// Call this function in your application if you wish to do all module 
// initialization.
// If you wish to not use some of the initializations, instead of the 
// Board_init use the individual Module_inits
//
//*****************************************************************************
void Board_init()
{
	EALLOW;

	PinMux_init();
	SYNC_init();
	CPUTIMER_init();
	EPWM_init();
	GPIO_init();
	INTERRUPT_init();

	EDIS;
}

//*****************************************************************************
//
// PINMUX Configurations
//
//*****************************************************************************
void PinMux_init()
{
	//
	// PinMux for modules assigned to CPU1
	//
	
	//
	// EPWM1 -> EPWM1_U Pinmux
	//
	GPIO_setPinConfig(EPWM1_U_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(EPWM1_U_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(EPWM1_U_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(EPWM1_U_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(EPWM1_U_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(EPWM1_U_EPWMB_GPIO, GPIO_QUAL_SYNC);

	// GPIO61 -> LED1_61 Pinmux
	GPIO_setPinConfig(GPIO_61_GPIO61);
	// GPIO62 -> LED2_62 Pinmux
	GPIO_setPinConfig(GPIO_62_GPIO62);
	// GPIO145 -> LED3_145 Pinmux
	GPIO_setPinConfig(GPIO_145_GPIO145);
	// GPIO146 -> LED4_146 Pinmux
	GPIO_setPinConfig(GPIO_146_GPIO146);

}


//*****************************************************************************
//
// CPUTIMER Configurations
//
//*****************************************************************************
void CPUTIMER_init(){
	myCPUTIMER0_init();
	myCPUTIMER1_init();
}

void myCPUTIMER0_init(){
	CPUTimer_setEmulationMode(myCPUTIMER0_BASE, CPUTIMER_EMULATIONMODE_STOPAFTERNEXTDECREMENT);
	CPUTimer_setPreScaler(myCPUTIMER0_BASE, 0U);
	CPUTimer_setPeriod(myCPUTIMER0_BASE, 199999999U);
	CPUTimer_enableInterrupt(myCPUTIMER0_BASE);
	CPUTimer_stopTimer(myCPUTIMER0_BASE);

	CPUTimer_reloadTimerCounter(myCPUTIMER0_BASE);
	CPUTimer_startTimer(myCPUTIMER0_BASE);
}
void myCPUTIMER1_init(){
	CPUTimer_setEmulationMode(myCPUTIMER1_BASE, CPUTIMER_EMULATIONMODE_STOPAFTERNEXTDECREMENT);
	CPUTimer_setPreScaler(myCPUTIMER1_BASE, 0U);
	CPUTimer_setPeriod(myCPUTIMER1_BASE, 99999999U);
	CPUTimer_enableInterrupt(myCPUTIMER1_BASE);
	CPUTimer_stopTimer(myCPUTIMER1_BASE);

	CPUTimer_reloadTimerCounter(myCPUTIMER1_BASE);
	CPUTimer_startTimer(myCPUTIMER1_BASE);
}

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
void EPWM_init(){
    EPWM_setClockPrescaler(EPWM1_U_BASE, EPWM_CLOCK_DIVIDER_4, EPWM_HSCLOCK_DIVIDER_4);	
    EPWM_setTimeBasePeriod(EPWM1_U_BASE, 2000);	
    EPWM_setTimeBaseCounter(EPWM1_U_BASE, 0);	
    EPWM_setTimeBaseCounterMode(EPWM1_U_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    EPWM_disablePhaseShiftLoad(EPWM1_U_BASE);	
    EPWM_setPhaseShift(EPWM1_U_BASE, 0);	
    EPWM_setCounterCompareValue(EPWM1_U_BASE, EPWM_COUNTER_COMPARE_A, 500);	
    EPWM_setCounterCompareShadowLoadMode(EPWM1_U_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(EPWM1_U_BASE, EPWM_COUNTER_COMPARE_B, 1500);	
    EPWM_setCounterCompareShadowLoadMode(EPWM1_U_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_disableActionQualifierShadowLoadMode(EPWM1_U_BASE, EPWM_ACTION_QUALIFIER_A);	
    EPWM_setActionQualifierShadowLoadMode(EPWM1_U_BASE, EPWM_ACTION_QUALIFIER_A, EPWM_AQ_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(EPWM1_U_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(EPWM1_U_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(EPWM1_U_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(EPWM1_U_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(EPWM1_U_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(EPWM1_U_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_disableActionQualifierShadowLoadMode(EPWM1_U_BASE, EPWM_ACTION_QUALIFIER_B);	
    EPWM_setActionQualifierShadowLoadMode(EPWM1_U_BASE, EPWM_ACTION_QUALIFIER_B, EPWM_AQ_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(EPWM1_U_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(EPWM1_U_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(EPWM1_U_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(EPWM1_U_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(EPWM1_U_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(EPWM1_U_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(EPWM1_U_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(EPWM1_U_BASE);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(EPWM1_U_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(EPWM1_U_BASE);	
}

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
void GPIO_init(){
	LED1_61_init();
	LED2_62_init();
	LED3_145_init();
	LED4_146_init();
}

void LED1_61_init(){
	GPIO_setPadConfig(LED1_61, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(LED1_61, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(LED1_61, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(LED1_61, GPIO_CORE_CPU1);
}
void LED2_62_init(){
	GPIO_setPadConfig(LED2_62, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(LED2_62, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(LED2_62, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(LED2_62, GPIO_CORE_CPU1);
}
void LED3_145_init(){
	GPIO_setPadConfig(LED3_145, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(LED3_145, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(LED3_145, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(LED3_145, GPIO_CORE_CPU1);
}
void LED4_146_init(){
	GPIO_setPadConfig(LED4_146, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(LED4_146, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(LED4_146, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(LED4_146, GPIO_CORE_CPU1);
}

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************
void INTERRUPT_init(){
	
	// Interrupt Settings for INT_myCPUTIMER0
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_myCPUTIMER0, &INT_myCPUTIMER0_ISR);
	Interrupt_enable(INT_myCPUTIMER0);
	
	// Interrupt Settings for INT_myCPUTIMER1
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_myCPUTIMER1, &INT_myCPUTIMER1_ISR);
	Interrupt_enable(INT_myCPUTIMER1);
}
//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************
void SYNC_init(){
	SysCtl_setSyncOutputConfig(SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT);
	//
	// SOCA
	//
	SysCtl_enableExtADCSOCSource(0);
	//
	// SOCB
	//
	SysCtl_enableExtADCSOCSource(0);
}
