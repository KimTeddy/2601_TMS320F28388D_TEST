//#############################################################################
//
// FILE:   empty_driverlib_main.c
//
//! \addtogroup driver_example_list
//! <h1>Empty Project Example</h1> 
//!
//! This example is an empty project setup for Driverlib development.
//!
//
//#############################################################################
//
//
// 
// C2000Ware v6.00.01.00
//
// Copyright (C) 2024 Texas Instruments Incorporated - http://www.ti.com
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################

//
// Included Files
//
#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "c2000ware_libraries.h"

__interrupt void INT_myCPUTIMER0_ISR(void) // CPUTIMER0 인터럽트 벡터로 들어오는 ISR(PIE 경유인 경우가 많음)
{
    GPIO_togglePin(DEVICE_GPIO_PIN_LED1);
    CPUTimer_clearOverflowFlag(myCPUTIMER0_BASE); // Timer0 오버플로(인터럽트 원인) 플래그를 클리어해서 다음 주기 인터럽트가 정상 발생하게 함
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);// PIE Group1 ACK를 클리어해서 같은 그룹의 다음 인터럽트가 CPU로 다시 들어올 수 있게 함
}

__interrupt void INT_myCPUTIMER1_ISR(void) // CPUTIMER1 인터럽트 벡터로 들어오는 ISR(보통 CPU INT13 쪽, PIE ACK 불필요)
{
    GPIO_togglePin(DEVICE_GPIO_PIN_LED2);
    CPUTimer_clearOverflowFlag(myCPUTIMER1_BASE); // Timer1 오버플로(인터럽트 원인) 플래그 클리어(재진입/연속 인터럽트 방지 및 다음 주기 준비)
}
//
// Main
//
void main(void)
{

    //
    // Initialize device clock and peripherals
    //
    Device_init();

    //
    // Disable pin locks and enable internal pull-ups.
    //
    Device_initGPIO();

    //
    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    //
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();

    //
    // PinMux and Peripheral Initialization
    //
    Board_init();//타이머 이 때 시작

    //
    // C2000Ware Library initialization
    //
    C2000Ware_libraries_init();

    GPIO_writePin(DEVICE_GPIO_PIN_LED1, 1U);
    GPIO_writePin(DEVICE_GPIO_PIN_LED2, 1U);
    GPIO_writePin(DEVICE_GPIO_PIN_LED3, 1U);
    GPIO_writePin(DEVICE_GPIO_PIN_LED4, 1U);

    CPUTimer_startTimer(myCPUTIMER0_BASE);
    CPUTimer_startTimer(myCPUTIMER1_BASE);
    //
    // Enable Global Interrupt (INTM) and real time interrupt (DBGM)
    //
    EINT;
    ERTM;
    // DEVICE_DELAY_US(5000000);   // 500 ms
    // CPUTimer_stopTimer(myCPUTIMER0_BASE);
    while(1)
    {
        // GPIO_togglePin(DEVICE_GPIO_PIN_LED4);
        // GPIO_togglePin(DEVICE_GPIO_PIN_LED2);
        // DEVICE_DELAY_US(500000);   // 500 ms
        // GPIO_togglePin(DEVICE_GPIO_PIN_LED2);
        // GPIO_togglePin(DEVICE_GPIO_PIN_LED3);
        // DEVICE_DELAY_US(500000);   // 500 ms
        // GPIO_togglePin(DEVICE_GPIO_PIN_LED3);
        // GPIO_togglePin(DEVICE_GPIO_PIN_LED4);
        // DEVICE_DELAY_US(500000);   // 500 ms
    }
}

//
// End of File
//
