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

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */
#include "../tools/blue.c"
#include "../tools/green.c"

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
    ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    InitApp();

    unsigned int i;
    uint8_t state = 0;
    uint8_t mapInc = 0;    
    
    TRISAbits.TRISA5 = 0;
    uint8_t blob[TABLESIZE];
    

    while(1)
    {
        LATAbits.LATA5 = state;
        for(i = 0; i < 50; i++)
            __delay_ms(10);
        state = ~state;
        
        //Zero out buffer
        for(i = 0; i < TABLESIZE; i++) {
            blob[i] = 0x00;
        }
        
        //Colourspace is 0xFFF levels
        //Dividing/multiplying by four to speed up the fade
        for(i = 0; i < 0x1000 / 4; i++) {
            setChannel(blob, mapInc, i * 4);
            LEDMap(blob);
        }
        
        mapInc = (mapInc + 1) % 24;
    }

}

