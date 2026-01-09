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
	GPIO_init();

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

