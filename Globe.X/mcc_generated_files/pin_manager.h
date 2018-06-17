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
        Driver Version    :  2.01
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

// get/set XLAT2 aliases
#define XLAT2_TRIS                 TRISAbits.TRISA2
#define XLAT2_LAT                  LATAbits.LATA2
#define XLAT2_PORT                 PORTAbits.RA2
#define XLAT2_WPU                  WPUAbits.WPUA2
#define XLAT2_OD                   ODCONAbits.ODA2
#define XLAT2_ANS                  ANSELAbits.ANSA2
#define XLAT2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define XLAT2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define XLAT2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define XLAT2_GetValue()           PORTAbits.RA2
#define XLAT2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define XLAT2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define XLAT2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define XLAT2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define XLAT2_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define XLAT2_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define XLAT2_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define XLAT2_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set SDI aliases
#define SDI_TRIS                 TRISBbits.TRISB4
#define SDI_LAT                  LATBbits.LATB4
#define SDI_PORT                 PORTBbits.RB4
#define SDI_WPU                  WPUBbits.WPUB4
#define SDI_OD                   ODCONBbits.ODB4
#define SDI_ANS                  ANSELBbits.ANSB4
#define SDI_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SDI_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SDI_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SDI_GetValue()           PORTBbits.RB4
#define SDI_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SDI_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SDI_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SDI_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SDI_SetPushPull()        do { ODCONBbits.ODB4 = 0; } while(0)
#define SDI_SetOpenDrain()       do { ODCONBbits.ODB4 = 1; } while(0)
#define SDI_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define SDI_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set XLAT1 aliases
#define XLAT1_TRIS                 TRISBbits.TRISB5
#define XLAT1_LAT                  LATBbits.LATB5
#define XLAT1_PORT                 PORTBbits.RB5
#define XLAT1_WPU                  WPUBbits.WPUB5
#define XLAT1_OD                   ODCONBbits.ODB5
#define XLAT1_ANS                  ANSELBbits.ANSB5
#define XLAT1_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define XLAT1_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define XLAT1_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define XLAT1_GetValue()           PORTBbits.RB5
#define XLAT1_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define XLAT1_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define XLAT1_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define XLAT1_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define XLAT1_SetPushPull()        do { ODCONBbits.ODB5 = 0; } while(0)
#define XLAT1_SetOpenDrain()       do { ODCONBbits.ODB5 = 1; } while(0)
#define XLAT1_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define XLAT1_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set SCK aliases
#define SCK_TRIS                 TRISBbits.TRISB6
#define SCK_LAT                  LATBbits.LATB6
#define SCK_PORT                 PORTBbits.RB6
#define SCK_WPU                  WPUBbits.WPUB6
#define SCK_OD                   ODCONBbits.ODB6
#define SCK_ANS                  ANSELBbits.ANSB6
#define SCK_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define SCK_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define SCK_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define SCK_GetValue()           PORTBbits.RB6
#define SCK_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define SCK_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define SCK_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define SCK_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define SCK_SetPushPull()        do { ODCONBbits.ODB6 = 0; } while(0)
#define SCK_SetOpenDrain()       do { ODCONBbits.ODB6 = 1; } while(0)
#define SCK_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define SCK_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set SDO aliases
#define SDO_TRIS                 TRISBbits.TRISB7
#define SDO_LAT                  LATBbits.LATB7
#define SDO_PORT                 PORTBbits.RB7
#define SDO_WPU                  WPUBbits.WPUB7
#define SDO_OD                   ODCONBbits.ODB7
#define SDO_ANS                  ANSELBbits.ANSB7
#define SDO_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define SDO_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define SDO_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define SDO_GetValue()           PORTBbits.RB7
#define SDO_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define SDO_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define SDO_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define SDO_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define SDO_SetPushPull()        do { ODCONBbits.ODB7 = 0; } while(0)
#define SDO_SetOpenDrain()       do { ODCONBbits.ODB7 = 1; } while(0)
#define SDO_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define SDO_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

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

// get/set SDO aliases
#define SDO_TRIS                 TRISCbits.TRISC2
#define SDO_LAT                  LATCbits.LATC2
#define SDO_PORT                 PORTCbits.RC2
#define SDO_WPU                  WPUCbits.WPUC2
#define SDO_OD                   ODCONCbits.ODC2
#define SDO_ANS                  ANSELCbits.ANSC2
#define SDO_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SDO_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SDO_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SDO_GetValue()           PORTCbits.RC2
#define SDO_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SDO_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SDO_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define SDO_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define SDO_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define SDO_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define SDO_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define SDO_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

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