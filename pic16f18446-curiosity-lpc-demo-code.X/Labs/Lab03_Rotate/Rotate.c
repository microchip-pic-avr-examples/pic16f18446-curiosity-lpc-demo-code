/**
  Rotate Lab Source File

  Company:
    Microchip Technology Inc.

  File Name:
    Rotate.c

  Summary:
    This is the source file for the Rotate lab

  Description:
    This source file contains the code on how the Rotate lab works.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.0
        Device            :  PIC16F18446
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB             :  MPLAB X 5.35
 */

/*
 (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
 */

/**
  Section: Included Files
 */

#include "../../mcc_generated_files/pin_manager.h"
#include "../../labs.h"

/**
  Section: Local Variable Declarations
 */
static uint8_t rotateReg;

/*
                             Application    
 */
void Rotate(void) {
    if (labState == NOT_RUNNING) {
        LEDs_SetLow();
        LED_D4_SetHigh();
        
        //Initialize temporary register to begin at 1
        rotateReg = 1;

        labState = RUNNING;
    }

    if (labState == RUNNING) {
        __delay_ms(500);

        rotateReg <<= 1;

        //If the last LED has been lit, restart the pattern
        if (rotateReg == LAST)
            rotateReg = 1;

        //Determine which LED will light up
        //ie. which bit in the register the 1 has rotated to.
        LED_D4_LAT = rotateReg & 1;
        LED_D5_LAT = (rotateReg & 2) >> 1;
        LED_D6_LAT = (rotateReg & 4) >> 2;
        LED_D7_LAT = (rotateReg & 8) >> 3;
    }

    if (switchEvent) {
        labState = NOT_RUNNING;
    }
}

/**
 End of File
 */
