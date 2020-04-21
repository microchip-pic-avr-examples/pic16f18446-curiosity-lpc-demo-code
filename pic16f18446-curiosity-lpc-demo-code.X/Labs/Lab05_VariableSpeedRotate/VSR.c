/**
  Variable Speed Rotate Lab Source File

  Company:
    Microchip Technology Inc.

  File Name:
    VSR.c

  Summary:
    This is the source file for the VSR lab

  Description:
    This source file contains the code on how the VSR lab works.
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
#include "../../mcc_generated_files/adcc.h"
#include "../../mcc_generated_files/eusart1.h"
#include "../../labs.h"

/**
  Section: Local Variable Declarations
 */
static uint8_t delay;
static uint8_t rotateReg;

/*
                             Application    
 */

void VSR(void) {
    if (labState == NOT_RUNNING) {
        LEDs_SetLow();

        //Initialize temporary register to begin at 1
        rotateReg = 1;

        labState = RUNNING;
    }

    if (labState == RUNNING) {
        // Use the top 8 MSbs of the ADC result as delay
        delay = ADCC_GetSingleConversion(POT_CHANNEL) >> 8;
        //Printing ADC result on Serial port
        printf("ADC Result: %d\n\r", ADRES >> 4);
        __delay_ms(2);

        // Decrement the 8 MSbs of the ADC and delay each for 2ms
        while (delay-- != 0) {
            __delay_ms(2);
        }

        //Determine which LED will light up
        LED_D4_LAT = rotateReg & 1;
        LED_D5_LAT = (rotateReg & 2) >> 1;
        LED_D6_LAT = (rotateReg & 4) >> 2;
        LED_D7_LAT = (rotateReg & 8) >> 3;

        rotateReg = rotateReg << 1;

        //Return to initial position of LED
        if (rotateReg == LAST) {
            rotateReg = 1;
        }
    }

    if (switchEvent) {
        labState = NOT_RUNNING;
    }
}
/**
 End of File
 */
