/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1619
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set XLAT1 aliases
#define XLAT1_TRIS                 TRISAbits.TRISA2
#define XLAT1_LAT                  LATAbits.LATA2
#define XLAT1_PORT                 PORTAbits.RA2
#define XLAT1_WPU                  WPUAbits.WPUA2
#define XLAT1_OD                   ODCONAbits.ODA2
#define XLAT1_ANS                  ANSELAbits.ANSA2
#define XLAT1_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define XLAT1_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define XLAT1_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define XLAT1_GetValue()           PORTAbits.RA2
#define XLAT1_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define XLAT1_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define XLAT1_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define XLAT1_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define XLAT1_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define XLAT1_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define XLAT1_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define XLAT1_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set HEF aliases
#define HEF_TRIS                 TRISBbits.TRISB4
#define HEF_LAT                  LATBbits.LATB4
#define HEF_PORT                 PORTBbits.RB4
#define HEF_WPU                  WPUBbits.WPUB4
#define HEF_OD                   ODCONBbits.ODB4
#define HEF_ANS                  ANSELBbits.ANSB4
#define HEF_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define HEF_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define HEF_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define HEF_GetValue()           PORTBbits.RB4
#define HEF_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define HEF_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define HEF_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define HEF_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define HEF_SetPushPull()        do { ODCONBbits.ODB4 = 0; } while(0)
#define HEF_SetOpenDrain()       do { ODCONBbits.ODB4 = 1; } while(0)
#define HEF_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define HEF_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set AUX1 aliases
#define AUX1_TRIS                 TRISBbits.TRISB5
#define AUX1_LAT                  LATBbits.LATB5
#define AUX1_PORT                 PORTBbits.RB5
#define AUX1_WPU                  WPUBbits.WPUB5
#define AUX1_OD                   ODCONBbits.ODB5
#define AUX1_ANS                  ANSELBbits.ANSB5
#define AUX1_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define AUX1_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define AUX1_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define AUX1_GetValue()           PORTBbits.RB5
#define AUX1_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define AUX1_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define AUX1_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define AUX1_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define AUX1_SetPushPull()        do { ODCONBbits.ODB5 = 0; } while(0)
#define AUX1_SetOpenDrain()       do { ODCONBbits.ODB5 = 1; } while(0)
#define AUX1_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define AUX1_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set AUX2 aliases
#define AUX2_TRIS                 TRISBbits.TRISB6
#define AUX2_LAT                  LATBbits.LATB6
#define AUX2_PORT                 PORTBbits.RB6
#define AUX2_WPU                  WPUBbits.WPUB6
#define AUX2_OD                   ODCONBbits.ODB6
#define AUX2_ANS                  ANSELBbits.ANSB6
#define AUX2_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define AUX2_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define AUX2_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define AUX2_GetValue()           PORTBbits.RB6
#define AUX2_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define AUX2_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define AUX2_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define AUX2_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define AUX2_SetPushPull()        do { ODCONBbits.ODB6 = 0; } while(0)
#define AUX2_SetOpenDrain()       do { ODCONBbits.ODB6 = 1; } while(0)
#define AUX2_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define AUX2_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set AUX3 aliases
#define AUX3_TRIS                 TRISBbits.TRISB7
#define AUX3_LAT                  LATBbits.LATB7
#define AUX3_PORT                 PORTBbits.RB7
#define AUX3_WPU                  WPUBbits.WPUB7
#define AUX3_OD                   ODCONBbits.ODB7
#define AUX3_ANS                  ANSELBbits.ANSB7
#define AUX3_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define AUX3_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define AUX3_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define AUX3_GetValue()           PORTBbits.RB7
#define AUX3_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define AUX3_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define AUX3_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define AUX3_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define AUX3_SetPushPull()        do { ODCONBbits.ODB7 = 0; } while(0)
#define AUX3_SetOpenDrain()       do { ODCONBbits.ODB7 = 1; } while(0)
#define AUX3_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define AUX3_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set BLANK1 aliases
#define BLANK1_TRIS                 TRISCbits.TRISC0
#define BLANK1_LAT                  LATCbits.LATC0
#define BLANK1_PORT                 PORTCbits.RC0
#define BLANK1_WPU                  WPUCbits.WPUC0
#define BLANK1_OD                   ODCONCbits.ODC0
#define BLANK1_ANS                  ANSELCbits.ANSC0
#define BLANK1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define BLANK1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define BLANK1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define BLANK1_GetValue()           PORTCbits.RC0
#define BLANK1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define BLANK1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define BLANK1_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define BLANK1_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define BLANK1_SetPushPull()        do { ODCONCbits.ODC0 = 0; } while(0)
#define BLANK1_SetOpenDrain()       do { ODCONCbits.ODC0 = 1; } while(0)
#define BLANK1_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define BLANK1_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set CLK1 aliases
#define CLK1_TRIS                 TRISCbits.TRISC1
#define CLK1_LAT                  LATCbits.LATC1
#define CLK1_PORT                 PORTCbits.RC1
#define CLK1_WPU                  WPUCbits.WPUC1
#define CLK1_OD                   ODCONCbits.ODC1
#define CLK1_ANS                  ANSELCbits.ANSC1
#define CLK1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define CLK1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define CLK1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define CLK1_GetValue()           PORTCbits.RC1
#define CLK1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define CLK1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define CLK1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define CLK1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define CLK1_SetPushPull()        do { ODCONCbits.ODC1 = 0; } while(0)
#define CLK1_SetOpenDrain()       do { ODCONCbits.ODC1 = 1; } while(0)
#define CLK1_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define CLK1_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set SIN1 aliases
#define SIN1_TRIS                 TRISCbits.TRISC2
#define SIN1_LAT                  LATCbits.LATC2
#define SIN1_PORT                 PORTCbits.RC2
#define SIN1_WPU                  WPUCbits.WPUC2
#define SIN1_OD                   ODCONCbits.ODC2
#define SIN1_ANS                  ANSELCbits.ANSC2
#define SIN1_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SIN1_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SIN1_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SIN1_GetValue()           PORTCbits.RC2
#define SIN1_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SIN1_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SIN1_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define SIN1_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define SIN1_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define SIN1_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define SIN1_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define SIN1_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set BLANK2 aliases
#define BLANK2_TRIS                 TRISCbits.TRISC3
#define BLANK2_LAT                  LATCbits.LATC3
#define BLANK2_PORT                 PORTCbits.RC3
#define BLANK2_WPU                  WPUCbits.WPUC3
#define BLANK2_OD                   ODCONCbits.ODC3
#define BLANK2_ANS                  ANSELCbits.ANSC3
#define BLANK2_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define BLANK2_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define BLANK2_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define BLANK2_GetValue()           PORTCbits.RC3
#define BLANK2_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define BLANK2_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define BLANK2_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define BLANK2_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define BLANK2_SetPushPull()        do { ODCONCbits.ODC3 = 0; } while(0)
#define BLANK2_SetOpenDrain()       do { ODCONCbits.ODC3 = 1; } while(0)
#define BLANK2_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define BLANK2_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set CLK2 aliases
#define CLK2_TRIS                 TRISCbits.TRISC4
#define CLK2_LAT                  LATCbits.LATC4
#define CLK2_PORT                 PORTCbits.RC4
#define CLK2_WPU                  WPUCbits.WPUC4
#define CLK2_OD                   ODCONCbits.ODC4
#define CLK2_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define CLK2_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define CLK2_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define CLK2_GetValue()           PORTCbits.RC4
#define CLK2_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define CLK2_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define CLK2_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define CLK2_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define CLK2_SetPushPull()        do { ODCONCbits.ODC4 = 0; } while(0)
#define CLK2_SetOpenDrain()       do { ODCONCbits.ODC4 = 1; } while(0)

// get/set SIN2 aliases
#define SIN2_TRIS                 TRISCbits.TRISC5
#define SIN2_LAT                  LATCbits.LATC5
#define SIN2_PORT                 PORTCbits.RC5
#define SIN2_WPU                  WPUCbits.WPUC5
#define SIN2_OD                   ODCONCbits.ODC5
#define SIN2_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SIN2_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SIN2_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SIN2_GetValue()           PORTCbits.RC5
#define SIN2_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SIN2_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SIN2_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define SIN2_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define SIN2_SetPushPull()        do { ODCONCbits.ODC5 = 0; } while(0)
#define SIN2_SetOpenDrain()       do { ODCONCbits.ODC5 = 1; } while(0)

// get/set XLAT2 aliases
#define XLAT2_TRIS                 TRISCbits.TRISC6
#define XLAT2_LAT                  LATCbits.LATC6
#define XLAT2_PORT                 PORTCbits.RC6
#define XLAT2_WPU                  WPUCbits.WPUC6
#define XLAT2_OD                   ODCONCbits.ODC6
#define XLAT2_ANS                  ANSELCbits.ANSC6
#define XLAT2_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define XLAT2_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define XLAT2_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define XLAT2_GetValue()           PORTCbits.RC6
#define XLAT2_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define XLAT2_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define XLAT2_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define XLAT2_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define XLAT2_SetPushPull()        do { ODCONCbits.ODC6 = 0; } while(0)
#define XLAT2_SetOpenDrain()       do { ODCONCbits.ODC6 = 1; } while(0)
#define XLAT2_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define XLAT2_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS                 TRISCbits.TRISC7
#define LED1_LAT                  LATCbits.LATC7
#define LED1_PORT                 PORTCbits.RC7
#define LED1_WPU                  WPUCbits.WPUC7
#define LED1_OD                   ODCONCbits.ODC7
#define LED1_ANS                  ANSELCbits.ANSC7
#define LED1_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define LED1_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define LED1_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define LED1_GetValue()           PORTCbits.RC7
#define LED1_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define LED1_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define LED1_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define LED1_SetPushPull()        do { ODCONCbits.ODC7 = 0; } while(0)
#define LED1_SetOpenDrain()       do { ODCONCbits.ODC7 = 1; } while(0)
#define LED1_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define LED1_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/