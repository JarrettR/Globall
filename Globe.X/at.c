#include <xc.h>
#include "at.h"

/**
  Section: AT APIs
*/

void AT_Initialize(void)
{
    // set the AT to the options selected in the User Interface
    // AT1CS FOSC; 
    AT1CLK = 0x00;
    // AT1SSEL ATINPPS pin; 
    AT1SIG = 0x00;
    // 
    AT1RESH = 0x00;
    // 
    AT1RESL = 0x07;
    // 
    AT1MISSH = 0x00;
    // 
    AT1MISSL = 0x00;
    // AT1POL rising edge; AT1EN enabled; AT1PREC reset; AT1APMOD Adaptive Missing Pulse mode; AT1PS AT1CLK; AT1MODE Single Pulse mode; 
    AT1CON0 = 0xC2;
    // AT1PRP Active high; AT1MPP Active high; AT1PHP Active high; 
    AT1CON1 = 0x00;
    // AT1PHSIF Angle Interrupt not occured; AT1PERIF Period Interrupt not occured; AT1MISSIF Missed Pulse Interrupt not occured; 
    AT1IR0 = 0x00;
    // AT1PHSIE enabled; AT1PERIE disabled; AT1MISSIE disabled; 
    AT1IE0 = 0x04;
    // AT1CC1IF Not occured; AT1CC3IF Not occured; AT1CC2IF Not occured; 
    AT1IR1 = 0x00;
    // AT1CC2IE disabled; AT1CC1IE disabled; AT1CC3IE disabled; 
    AT1IE1 = 0x00;
    // 
    AT1STPTH = 0x00;
    // 
    AT1STPTL = 0x8C;
    // 
    AT1CC1H = 0x00;
    // 
    AT1CC1L = 0x6B;
    // AT1CAP1P rising edge; AT1CC1POL Active high; AT1CC1EN disabled; AT1CC1MODE capture mode; 
    AT1CCON1 = 0x01;
    // AT1CP1S AT1CC1 pin; 
    AT1CSEL1 = 0x00;
    // 
    AT1CC2H = 0x00;
    // 
    AT1CC2L = 0x00;
    // AT1CC2EN disabled; AT1CAP2P rising edge; AT1CC2POL Active high; AT1CC2MODE compare mode; 
    AT1CCON2 = 0x00;
    // AT1CP2S AT1CC2 pin; 
    AT1CSEL2 = 0x00;
    // 
    AT1CC3H = 0x00;
    // 
    AT1CC3L = 0x00;
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

void AT_MissingPulseDelaySet(int16_t missingPulse)
{
    AT1MISSH = (uint8_t)(((uint16_t)missingPulse & 0xFF00)>>8);	//writing 8 MSBs to AT1MISSH register
    AT1MISSL = (uint8_t)((uint16_t)missingPulse & 0x00FF);		//writing 8 LSBs to AT1MISSL register
}

void AT_SetPointLoad(uint16_t thresholdPeriod)
{
    AT1STPTH = (uint8_t)((thresholdPeriod & 0x7F00)>>8);	//writing 7 MSBs to AT1STPTH register
    AT1STPTL = (uint8_t)(thresholdPeriod & 0x00FF);       //writing 8 LSBs to AT1STPTL register
}

uint16_t AT_PeriodGet(void)
{
    return ((uint16_t)((AT1PERH << 8) | AT1PERL));		//return 15 bit (Period) AT1PER register
}

uint16_t AT_PhaseGet(void)
{
    return ((uint16_t)((AT1PHSH << 8) | AT1PHSL));		//return 10 bit (Phase)AT1PHS register
}

int16_t AT_SetPointErrorGet(void)
{
    return ((uint16_t)((AT1ERRH << 8) | AT1ERRL));		//return 16 bit AT1ERR register
}

bool AT_CheckPeriodValue(void)
{
    return (AT1CON1bits.AT1ACCS);
}

bool AT_IsMeasurementValid(void)
{
    return (AT1CON1bits.AT1VALID);
}

bool AT_IsPeriodCounterOverflowOccured(void)
{
    return (AT1PERHbits.AT1POV);
}

bool AT_IsPeriodCountAvailable(void)
{
    return (AT1IR0bits.AT1PERIF);
}

bool AT_IsPhaseCountAvailable(void)
{
    return (AT1IR0bits.AT1PHSIF);
}

bool AT_IsMissedPulseCountAvailable(void)
{
    return (AT1IR0bits.AT1MISSIF);
}







void AT_ISR(void)
{
    PIR5bits.AT1IF = 0;
    if(AT1IR0bits.AT1PHSIF)
    {
        AT_Phase();
    }
}


void AT_Phase(void)
{
    static uint8_t state = 1;
    AT1IR0bits.AT1PHSIF = 0;
    LATAbits.LATA5 = state;
    state = ~state;
}




        
/**
 End of File
*/
