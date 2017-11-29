#include <xc.h>
#include "at.h"

/**
  Section: AT APIs
*/

void AT_Initialize(void)
{
    // 
    AT1RESH = 0x00;
    // 
    AT1RESL = 0x37;
    // 
    AT1MISSH = 0x00;
    // 
    AT1MISSL = 0x00;
    // AT1POL rising edge; AT1EN enabled; AT1PREC reset; AT1APMOD Adaptive Missing Pulse mode; AT1PS AT1CLK/4; AT1MODE Single Pulse mode; 
    AT1CON0 = 0xE2;
    // AT1PRP Active high; AT1MPP Active high; AT1PHP Active high; 
    AT1CON1 = 0x00;
    // AT1PHSIF Angle Interrupt not occurred; AT1PERIF Period Interrupt not occurred; AT1MISSIF Missed Pulse Interrupt not occurred; 
    AT1IR0 = 0x00;
    // AT1PHSIE enabled; AT1PERIE enabled; AT1MISSIE disabled; 
    AT1IE0 = 0x05;
    // AT1CC1IF Not occurred; AT1CC3IF Not occurred; AT1CC2IF Not occurred; 
    AT1IR1 = 0x00;
    // AT1CC2IE disabled; AT1CC1IE disabled; AT1CC3IE disabled; 
    AT1IE1 = 0x00;
    // AT1CAP1P rising edge; AT1CC1POL Active high; AT1CC1EN disabled; AT1CC1MODE capture mode; 
    AT1CCON1 = 0x01;
    // AT1CP1S AT1CC1 pin; 
    AT1CSEL1 = 0x00;
    // AT1CC2EN disabled; AT1CAP2P rising edge; AT1CC2POL Active high; AT1CC2MODE compare mode; 
    AT1CCON2 = 0x00;
    // AT1CP2S AT1CC2 pin; 
    AT1CSEL2 = 0x00;
    // AT1CC3EN disabled; AT1CAP3P rising edge; AT1CC3POL Active high; AT1CC3MODE compare mode; 
    AT1CCON3 = 0x00;
    // AT1CP3S AT1CC3 pin; 
    AT1CSEL3 = 0x00;

    // Clear the AT interrupt flag
    PIR5bits.AT1IF = 0;
        
    // Enabling AT interrupt.
    PIE5bits.AT1IE = 1;
}


void AT_ResolutionSet(uint16_t resolution)
{
    AT1RESH = (uint8_t)((resolution & 0x0300)>>8);	//writing 2 MSBs to AT1RESH register
    AT1RESL = (uint8_t)(resolution & 0x00FF);	//writing 8 LSBs to AT1RESL register	
}

inline void AT_ISR(void)
{
    PIR5bits.AT1IF = 0;
    if(AT1IR0bits.AT1PERIF)
    {
        AT_Period();
    }
    if(AT1IR0bits.AT1PHSIF)
    {
        AT_Phase();
    }
}


inline void AT_Period(void)
{
    static uint8_t state = 1;
    AT1IR0bits.AT1PERIF = 0;
    LATAbits.LATA5 = state;
    state = ~state;
    angleInt = 0;
}
inline void AT_Phase(void)
{
    //static uint8_t state = 1;
    AT1IR0bits.AT1PHSIF = 0;
    //LATAbits.LATA5 = state;
    //state = ~state;
    angleInt++;
}
   
/**
 End of File
*/
