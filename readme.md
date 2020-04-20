# INTRODUCTION

The following labs in this demo code project are designed for Microchip’s Curiosity High Pin Count (HPC) Development board. This development board supports Microchip's 28 and 40-pin 8-bit PIC® MCUs. This MPLAB X project contains several lab exercises that demonstrate a large number of basic capabilities of PIC® devices and can also be used to test the condition of the board. Each lab contains a brief description of the lab and discussions to make you become easily acquainted with the different peripherals and registers of PIC® MCUs. These labs also make use of the MPLAB Code Configurator (MCC), an easy-to-use plugin tool for MPLAB X IDE that you can use to generate codes for a more efficient use of the CPU and memory resources. All labs are written in C language and are compatible with the latest XC8 compilers.

##### Curiosity High Pin Count (HPC) Development Board:
![Curiosity High Pin Count (HPC) Development Board](images/HPC-board.PNG)

## Software Used
     - MPLAB® X IDE 5.35 or newer [(microchip.com/mplab/mplab-x-ide)](http://www.microchip.com/mplab/mplab-x-ide)
     - MPLAB® XC8 2.10 or a newer compiler [(microchip.com/mplab/compilers)](http://www.microchip.com/mplab/compilers)
     - MPLAB® Code Configurator (MCC) 3.95.0 or newer [(microchip.com/mplab/mplab-code-configurator)](https://www.microchip.com/mplab/mplab-code-configurator)
     - MPLAB® Code Configurator (MCC) Device Libraries PIC10 / PIC12 / PIC16 / PIC18 MCUs [(microchip.com/mplab/mplab-code-configurator)](https://www.microchip.com/mplab/mplab-code-configurator)
     - Microchip PIC18F-Q Series Device Support (1.4.109) or newer [(packs.download.microchip.com/)](https://packs.download.microchip.com/)

## Hardware Used
     - [(PIC18F47Q10 Microcontroller)](https://www.microchip.com/wwwproducts/en/PIC18F47Q10)
     - [(Curiosity High Pin Count (HPC) Development Board)](https://www.microchip.com/developmenttools/ProductDetails/PartNO/DM164136)     

## LABS
The labs in this project are presented in the same order as they appear on the programmed labs. You can progress through each of the labs by simply pressing the S1 button on the board.

• Lab 1: Hello World (Turn On an LED) <br />
• Lab 2: Blink <br />
• Lab 3: Rotate (Moving the Light Across LEDs) <br />
• Lab 4: Analog-to-Digital Conversion (ADC) <br />
• Lab 5: Variable Speed Rotate <br />
• Lab 6: Pulse-Width Modulation (PWM) <br />
• Lab 7: Timers <br />
• Lab 8: Interrupts <br />
• Lab 9: Wake-up from Sleep Using Watchdog Timer <br />
• Lab 10: EEPROM <br />

## INPUTS AND DISPLAY
• Push Button Switch – Only one on-board push button switch S1 is utilized. S1 is connected to the PIC MCU’s RB4 pin and is used to switch to the next lab. <br />
• Potentiometer – A 10kΩ potentiometer connected to the RA0 pin is used in labs requiring analog inputs. <br />
• LEDs - The Curiosity HPC Development Board has four LEDs (D2 through D5) that are connected to I/O ports RA4 through RA7, respectively. These LEDs are used to display the output of the different labs. <br/>

### Lab 1: Hello World
#### Introduction
This lab shows how to turn on an LED.

#### Hardware Effects
LED D2 will light up and stay lit.

#### Summary
The LEDs are connected to the input-output (I/O) pins. First, the I/O pin must be configured to be an output. In this case, when one of these pins is driven high (LED_D2 = 1), the LED will turn on. These two logic levels are derived from the power pins of the PIC MCU. Since the PIC's power pin (VDD) is connected to 5V or 3.3V and the source (VSS) to ground (0V), a logic level of ‘1’ is equivalent to 5V or 3.3V, and a logic level of ‘0’ is 0V.


### Lab 2: Blink
#### Introduction
This lab shows how to blink an LED.

#### Hardware Effects
LED D2 blinks at a rate of approximately 1.5 seconds.

#### Summary
One way to create a delay is to spend time decrementing a value. In assembly, the timing can be accurately programmed since the user will have direct control on how the code is executed. In 'C', the compiler takes the 'C' and compiles it into assembly before creating the file to program to the actual PIC MCU (HEX file). Because of this, it is hard to predict exactly how many instructions it takes for a line of 'C' to execute. For a more accurate timing in C, this lab uses the MCU’s TIMER1 module to produce the desired delay. TIMER1 is discussed in Lab 7: Timers.


### Lab 3: ROTATE
#### Introduction
This lab is built on Lab 1 and 2, which showed how to light up a LED and then make it blink using loops. This lab incorporates four onboard LEDs (D2, D3, D4 and D5) and the program will light up each LED in turn.

#### Hardware Effects
LEDs D2, D3, D4 and D5 light up in turn every 500 milliseconds. Once D5 is lit, D2 lights up and the pattern repeats.

#### Summary
In C, we use Binary Left Shift and Right Shift Operators (<< and >>, respectively) to move bits around in the registers. The shift operations are 9-bit operations involving the 8-bit register being manipulated and the Carry bit in the STATUS register as the ninth bit. With the rotate instructions, the register contents are rotated through the Carry bit. <br />

For example, for a certain register rotateReg, we want to push a ‘1’ into the LSB of the register and have the rest of the bits shift to the left, we can use the Binary Left Shift Operator (<<). We would first have to set up the Carry bit with the value that we want to push into the register before we execute shift instruction, as seen in the figure below.

###### Left Shift Binary Operation
![Lab3-left-shift-binary-operation](images/Lab3-left-shift-binary-operation.PNG)

Similarly, if we want to push a ‘1’ into the MSB of the register and have the rest of the bits shift to the right, we can use the Binary Right Shift Operator (>>). We would first have to set up the Carry bit with the value that we want to push into the register before we execute shift instruction, as seen in  the figure below.

###### Right Shift Binary Operation
![Lab3-right-shift-binary-operation](images/Lab3-right-shift-binary-operation.PNG)


### Lab 4: ANALOG-TO-DIGITAL CONVERSION (ADC)
#### Introduction
This lab shows how to configure the ADC, run a conversion, read the analog voltage controlled by the on-board potentiometer, print the conversion result on UART and display the high order four bits on the display.

#### Hardware Effects
The four most significant bits of the ADC result are reflected onto each of the four LEDs respectively. Rotate the potentiometer to change the display. The ADC value will be printed on UART TX pin which is connected to pin RC5 through PPS. Connect this pin to the Virtual COM port's TX pin using a jumper wire to use the onboard serial to USB feature.

#### Summary
The PIC devices have an on-board Analog-to-Digital Converter (ADC) with 12 bits of resolution. Several devices feature the Analog-to-Digital Converter with Computation which can also be configured to operate in basic mode similar to the legacy ADC operation. (Note: The type of ADC, channels and resolution vary amongst the devices. Refer to the datasheet for more detail.) The converter can be referenced to the device’s VDD or an external voltage reference. This lab references it to VDD. The result from the ADC is represented by a ratio of the voltage to the reference.


### Lab 5: VARIABLE SPEED ROTATE
#### Introduction
This lab combines all of the previous lab to produce a variable speed rotating LED display that is proportional to the ADC value. The ADC value and LED rotate speed are inversely proportional to each other.
#### Hardware Effects
Rotate the clockwise to see the LEDs shift faster. The ADC value will be printed on UART TX pin which is connected to pin RC5 through PPS. Connect this pin to the Virtual COM port's TX pin using a jumper wire to use the onboard serial to USB feature.
#### Summary
A crucial step in this lab is to check if the ADC value is 0. If it does not perform the zero check, and the ADC result is zero, the LEDs will rotate at an incorrect speed. This is an effect of the delay value underflowing from 0 to 255.

![Lab 5 Program Flow](images/Lab5-program-flow.PNG)

### Lab 6: PULSE-WIDTH MODULATION (PWM)
#### Introduction
In this lab, the PIC MCU generates a PWM signal that lights an LED with the potentiometer thereby controlling the brightness.
#### Hardware Effects
Rotating potentiometer will adjust the brightness of LED D5. The ADC value will be printed on UART TX pin which is connected to pin RC5 through PPS. Connect this pin to the Virtual COM port's TX pin using a jumper wire to use the onboard serial to USB feature.
#### Summary
Pulse-Width Modulation (PWM) is a scheme that provides power to a load by switching quickly between fully ON and fully OFF states. The PWM signal resembles a square wave where the high portion of the signal is considered the ON state and the low portion of the signal is considered the OFF state. The high portion, also known as the pulse width, can vary in time and is defined in steps. A longer, high ON time will illuminate the LED brighter. The frequency or period of the PWM does not change. The PWM period is defined as the duration of one cycle or the total amount of ON and OFF time combined. Another important term to take note is the PWM duty cycle which is the ratio of the pulse width to the period and is often expressed in percentage. A lower duty cycle corresponds to less power applied and a higher duty cycle corresponds to more power applied.


### Lab 7: TIMERS
#### Introduction
This lab will produce the same output as Lab 3: ROTATE. The only difference is that this version uses Timer1 to provide the delay routine.
#### Hardware Effects
LEDs rotate from right to left, similar to Lab 3.
#### Summary
Timer1 is a counter module that uses two 8-bit paired registers (TMR1H:TMR1L) to implement a 16-bit timer/counter in the processor. It may be used to count instruction cycles or external events that occur at or below the instruction cycle rate. <br />
This lab configures Timer1 to count instruction cycles and to set a flag when it rolls over. This frees up the processor to do meaningful work rather than wasting instruction cycles in a timing loop. Using a counter provides a convenient method of measuring time or delay loops as it allows the processor to work on other tasks rather than counting instruction cycles.


### Lab 8: INTERRUPTS
#### Introduction
This lab discusses all about interrupts – its purpose, capabilities and how to set them up. Most interrupts are sourced from MCU peripheral modules. Some I/O pins can also be configured to generate interrupts whenever a change in state is detected. Interrupts usually signal events that require servicing by the software’s Interrupt Service Routine (ISR). Once an interrupt occurs, the program counter immediately jumps to the ISR and once the Interrupt Flag is cleared, resumes what it was doing before. It is a rather more efficient way of watching out for events than continuously polling a bit or register.
#### Hardware Effects
LEDs D5, D4, D3 and D2 rotate from left to right at a constant rate of 499.712 ms.
#### Summary
This lab demonstrates the advantage of using interrupts over polling. An interrupt is generated whenever the Timer0 register reaches 0xFF and goes back to reset value. This indicates that 500 ms has passed and it is time to rotate the light. This interrupt is serviced by the TMR0_ISR() function. Note that this is the same for Lab 7: TIMER1 but this time, we are not continuously watching the TMR1IF flag.


### Lab 9: WAKE-UP FROM SLEEP USING WATCHDOG TIMER
#### Introduction
This lab will introduce the Sleep mode. SLEEP() function is used to put the device into a low power standby mode.
#### Hardware Effects
Once this lab is on RUNNING state, the watchdog timer will start counting. While in Sleep mode, LEDs D2/D4 and LEDs D3/D5 are turned ON and OFF respectively. Pressing the switch won't go to the next lab since the PIC is in Sleep mode. After the watchdog timer has reached its period, which is approximately 4 seconds for this lab, the PIC exits sleep mode and the four LEDs, D2 through D5, are toggled.
#### Summary
The Power-Down mode is entered by executing the SLEEP instruction. Upon entering Sleep mode, there are different conditions that can exist such as:
• WDT will be cleared but keeps running, if enabled for operation during Sleep.
• PD bit of the STATUS register is cleared.
• TO bit of the STATUS register is set.
• CPU clock is disabled.
Different PICs have different condition once they enter Sleep mode so it is recommended that the reader refer to the datasheet to know more of these conditions. <br />
The Watchdog Timer (WDT) is a system timer that generates a Reset if the firmware does not issue a CLRWDT instruction within the time-out period. WDT is typically used to recover the system from unexpected events. When the device enters Sleep, the WDT is cleared. If the WDT is enabled during Sleep, the WDT resumes counting. When the device exits Sleep, the WDT is cleared again. When a WDT time-out occurs while the device is in Sleep, no Reset is generated.


### Lab 10: EEPROM
#### Introduction
This lab provides code for writing and reading a single byte onto the on-board EEPROM. EEPROM is nonvolatile memory, meaning that it does not lose its value when power is shut off. This is unlike RAM, which will lose its value when no power is applied. The EEPROM is useful for storing variables that must still be present during no power. It is also convenient to use if the entire RAM space is used up. Writes and reads to the EEPROM are relatively quick, and are much faster than program memory operations.
#### Hardware Effects
The top 4 MSBs of the ADC is written to EEPROM. These are read afterwards and displayed on the LEDs. Rotating the potentiometer changes value of the ADC to be written to and read from EEPROM.
#### Summary
This lab has a similar appearance to Lab 4: ADC. But instead of directly moving the ADC result directly onto the LEDs, it performs a simple “write” and “read” on the EEPROM. As shown on FIGURE 10-1 below, the top 4 MSBs of the ADC result is first written to EEPROM, and retrieved later from the same address before moving onto the LEDs.

![Lab 5 Program Flow](images/Lab10-program-flow.PNG)
