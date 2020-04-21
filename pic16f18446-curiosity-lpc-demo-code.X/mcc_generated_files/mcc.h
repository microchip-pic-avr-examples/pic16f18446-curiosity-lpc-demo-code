/**
  @Generated PIC10 / PIC12 / PIC16 / PIC18 MCUs Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    mcc.h

  @Summary:
    This is the mcc.h file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.0
        Device            :  PIC16F18446
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above or later
        MPLAB             :  MPLAB X 5.35
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef MCC_H
#define	MCC_H
#include <xc.h>
#include "device_config.h"
#include "pin_manager.h"
#include <stdint.h>
#include <stdbool.h>
#include <conio.h>
#include "interrupt_manager.h"
#include "tmr1.h"
#include "tmr2.h"
#include "tmr0.h"
#include "adcc.h"
#include "pwm1.h"
#include "memory.h"
#include "eusart1.h"

#define WDTCWS  7
#define WDTCPS  24
#define WDTCCS  0


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Initializes the device to the default states configured in the
 *                  MCC GUI
 * @Example
    SYSTEM_Initialize(void);
 */
void SYSTEM_Initialize(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Initializes the oscillator to the default states configured in the
 *                  MCC GUI
 * @Example
    OSCILLATOR_Initialize(void);
 */
void OSCILLATOR_Initialize(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Initializes the PMD module to the default states configured in the
 *                  MCC GUI
 * @Example
    PMD_Initialize(void);
 */
void PMD_Initialize(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Initializes the WWDT to the default states configured in the
 *                  MCC GUI
 * @Example
    WWDT_Initialize();
 */
void WWDT_Initialize(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
   Enable the WWDT by setting the SEN bit.
 * @Example
    WWDT_SoftEnable();
 */
void WWDT_SoftEnable(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
   Disable the WWDT by clearing the SEN bit.
 * @Example
    WWDT_SoftDisable();
 */
void WWDT_SoftDisable(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
   Disable the interrupt, arm the WWDT by reading back the WDTCON0 register
 * clear the WWDT and enable the interrupt.
 * @Example
    WWDT_TimerClear();
 */
void WWDT_TimerClear(void);

/**
 * @Param
    none
 * @Returns
   High --> WWDT reset has not occurred. 
 * Low  --> WWDT reset has  occurred.
 * @Description
    Returns the status of whether the WWDT reset has occurred or not.
 * @Example
    if(WWDT_TimeOutStatusGet())
 */
bool WWDT_TimeOutStatusGet(void);

/**
 * @Param
    none
 * @Returns
   High --> WWDT window violation reset has not occurred. 
 * Low  --> WWDT window violation reset has  occurred.
 * @Description
    Returns the status of, whether the WWDT window violation 
 *  reset has occurred or not.
 * @Example
    if(WWDT_WindowViolationStatusGet())
 */
bool WWDT_WindowViolationStatusGet(void);
      

#endif	/* MCC_H */
/**
 End of File
*/