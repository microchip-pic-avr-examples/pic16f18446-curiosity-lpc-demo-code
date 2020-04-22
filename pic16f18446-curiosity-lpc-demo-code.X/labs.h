/**
  Lab Header File

  @Company
    Microchip Technology Inc.

  @File Name
    labs.h

  @Summary
    This is the header file for the variables declarations and function prototypes

  @Description
    This header file provides all the variables and function prototypes used in this project.
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

#ifndef LABS_H
#define	LABS_H

#include <xc.h>
#include <stdint.h>
    

/**
  Section: Macro Declarations
 */
    #define _XTAL_FREQ          500000
    #define PRESSED             1
    #define NOT_PRESSED         0
    #define RUNNING             1
    #define NOT_RUNNING         0
    #define LAST                16
    #define LEDs_SetLow()       do { LATA = 0; LATCbits.LATC5 = 0; } while(0)

    #define INTERRUPT_TMR0InterruptEnable()         do { TMR0IE = 1; } while(0)
    #define INTERRUPT_TMR0InterruptDisable()        do { TMR0IE = 0; } while(0)

/**
  Section: Variable Definitions
 */
    uint8_t labNumber = 0;
    uint8_t switchEvent = 0;
    uint8_t labState = NOT_RUNNING;
    uint8_t btnState = NOT_PRESSED;    

/**
  Section: Function Prototypes
 */
    
/**
  @Summary
    Performs the HelloWorld Lab.

  @Description
    This turns on LED_D4 on the Curiosity Board. 

  @Preconditions
    SYSTEM_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void HelloWorld(void);

/**
  @Summary
    Performs the Blink Lab.

  @Description
    LED_D4 blinks at a rate of approximately 1.5 seconds. 

  @Preconditions
    SYSTEM_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void Blink(void);

/**
  @Summary
    Performs the Rotate Lab.

  @Description
    The LEDs rotate from right to left at a rate of 0.5s. 

  @Preconditions
    SYSTEM_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void Rotate(void);

/**
  @Summary
    Performs the Analog to Digital Conversion Lab.

  @Description
    The top 4 MSbs of the ADC are displayed on the LEDs. Rotate the potentiometer 
    to change the display. 

  @Preconditions
    SYSTEM_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void ADC(void);

/**
  @Summary
    Performs the Variable Speed Rotate Lab.

  @Description
    The LEDs rotate from right to left similar to Rotate Lab with varying speed.
    Rotate the POT counterclockwise to see the LEDs shift faster.

  @Preconditions
    SYSTEM_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void VSR(void);

/**
  @Summary
    Performs the Pulse Width Modulation Lab.

  @Description
    Rotating the potentiometer will adjust the brightness of a single LED, LED_D7. 
    

  @Preconditions
    SYSTEM_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void PWM(void);

/**
  @Summary
    Performs the Timer1 Lab.

  @Description
    The LEDs rotate from right to left, similar to Rotate Lab, at a rate of ~0.5 seconds.

  @Preconditions
    SYSTEM_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void Timer1(void);

/**
  @Summary
    Performs the Interrupt Lab.

  @Description
    The LEDs rotate at a constant speed of ~0.5s from left to right.

  @Preconditions
    SYSTEM_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void Interrupt(void);

/**
  @Summary
    Performs the Sleep-Wakeup Lab.

  @Description
    LED_D4 and LED_D6 are ON while the MCU is in sleep mode. After 4 seconds, the Watchdog 
    Timer will wake up the device from sleep then both LED_D5 and LED_D7 will turn ON, 
    while LED_D4 and LED_D6 will turn OFF. 

  @Preconditions
    SYSTEM_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void SleepWakeUp(void);

/**
  @Summary
    Performs the EEPROM Lab.

  @Description
   The top 4 MSBs of the ADC is written to EEPROM. These are read 
   afterwards and displayed on the LEDs. Rotating the potentiometer changes value of the 
   ADC to be stored/read to/from EEPROM. 

  @Preconditions
    SYSTEM_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void EEPROM(void);

#endif	/* LABS_H */
/**
 End of File
 */
 
 
 