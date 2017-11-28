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
#include "at.h"
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
    ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    InitApp();

    unsigned int i;
    unsigned int frame;
    unsigned int angleInt = 0;
    uint8_t state = 0;
    uint8_t mapInc = 5;    
    
    TRISAbits.TRISA5 = 0;
    uint8_t blob[TABLESIZE];
    
    //Zero out buffer
    for(i = 0; i < TABLESIZE; i++) {
        blob[i] = 0x00;
    }

    frame = 1;
    
    while(1)
    {
        
        //if (frame != angleInt) {
            LATAbits.LATA5 = state;
            frame = angleInt % HPIXELS;
            if(frame == 0) {
                state = ~state;
            }
            for(i = 0; i < TABLESIZE; i++) {
                blob[i] = 0x00;
            }
            for(i = 0; i < VPIXELS; i++) {
                setChannel(blob, i, blueMap[frame][i]);
                setChannel(blob, 23 - i, greenMap[frame][i]);
            }
            LEDMap(blob);
            
            __delay_ms(10);
            angleInt++;
        //}
    }

}

