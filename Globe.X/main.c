/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#endif

#include "mcc_generated_files/mcc.h" 
#include "user.h" 
#include "at.h"
#include "gamma.h"
#include "../tools/blue.h"
#include "../tools/green.h"


/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

void main(void)
{
    /* Configure the oscillator for the device */
    //ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    //InitApp();
    SYSTEM_Initialize();

    unsigned int i;
    uint8_t x;
    unsigned int frame;
    uint8_t mapInc = 5;    
    
    BLANK1_SetLow();
    XLAT1_SetLow();
    
    
    uint8_t blob[TABLESIZE];
    
    //Zero out buffer
    for(i = 0; i < TABLESIZE; i++) {
        blob[i] = 0x00;
    }

    frame = 0;
    
    AT_ResolutionSet(HPIXELS - 1);
    
    //EnableInterrupts();
    DisableInterrupts();
    x = 0;
    
    
    while(1)
    {
        
            
        LED1_Toggle();
        __delay_ms(500);
        //LEDSingle(x);
        x++;
        for(i = 0; i < TABLESIZE; i++) {
            blob[i] = 0x00;
        }
        
        for(i = 0; i < 0xff; i++) {

            setChannel(blob, mapInc, gamma[i] << 16);
            LEDMap(blob);
        }
        
        mapInc = (mapInc + 1) % 24;
    }

}

