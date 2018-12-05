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
    uint16_t delayTimer = 0;
    uint8_t testLed = 0;    
    unsigned int frame;
    uint8_t mapInc = 5;    
    
    //BLANK1_SetHigh();
    XLAT1_SetLow();
    
    
    uint8_t blob[TABLESIZE];
    
    //Zero out buffer
    for(i = 0; i < TABLESIZE; i++) {
        blob[i] = 0x00;
    }

    frame = 0;
    angleInt = 0;
    
    AT_ResolutionSet(HPIXELS - 1);
    
    EnableInterrupts();
    //DisableInterrupts();
    
    for(i = 0; i < VPIXELS; i++) {
        setChannel(blob, i, 0xFFFF);
    }
    LEDMap(blob);
    
    while(1)
    {
        //Green LED mirrors HEF sensor for alignment with magnets
        //LEDs display a test pattern
        if(!AT_IsMeasurementValid()) {
            //DisableInterrupts();
            
            //Magnet calibration mode
            LED1_LAT = HEF_GetValue();
            
            delayTimer++;
            
            if(delayTimer == 0xFFFF) {
                for(i = 0; i < VPIXELS; i++) {
                    //x =  (blueMap[frame][i] << 4) & blueMap[frame][i];
                    //setChannel(blob, i, blueMap[frame][i]);
                    setChannel(blob, i, 0);
                    setChannel(blob, testLed, 0xFFF);
                    //setChannel(blob, 23 - i, greenMap[frame][i]);
                }
                LEDMap(blob);
                testLed = ++testLed % VPIXELS;
            }
            
        } else {
            LED1_SetLow();
            //EnableInterrupts();
        
            if (frame != angleInt && angleInt < HPIXELS) {
                //frame = (frame + 1 ) % HPIXELS;
                frame = angleInt;

                DisableInterrupts();
                for(i = 0; i < VPIXELS; i++) {
                    //x =  (blueMap[frame][i] << 4) & blueMap[frame][i];
                    setChannel(blob, i, blueMap[frame][i]);
                    //setChannel(blob, 23 - i, greenMap[frame][i]);
                }
                LEDMap(blob);
                EnableInterrupts();
                //__delay_ms(100);
            }
        }
        
    }

}

