/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>    /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#endif

#include "user.h"
#include "at.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/
void setChannel(uint8_t *blob, uint8_t channel, uint16_t value) {
    uint8_t lvalue;
    uint8_t rvalue;
    uint8_t newVal;
    uint8_t byteAddr;
    
    if(channel % 2 == 0) {
        byteAddr = (channel * 3) / 2;
        lvalue = (uint8_t)(value & 0xFF);
        rvalue = (uint8_t)(value >> 8);
        
        *(blob + byteAddr) = lvalue;
        newVal = (*(blob + byteAddr + 1)) & 0xF0;
        newVal = rvalue | newVal;
        
        *(blob + byteAddr + 1) = newVal;
    } else {
        byteAddr = (((channel - 1) * 3) / 2) + 1;
        
        lvalue = (uint8_t)(value << 4) & 0xF0;
        rvalue = (uint8_t)(value >> 4);
        
        newVal = (*(blob + byteAddr)) & 0x0F;
        newVal = lvalue | newVal;
        
        *(blob + byteAddr) = newVal;
        *(blob + byteAddr + 1) = rvalue;
    }
}

void LEDMap(uint8_t *blob)
{
    uint8_t data = 0;
    
    XLAT = 0;
    
    for(int i = TABLESIZE - 1; i >= 0; i--) {
        data = *(blob + i);
        SPIWrite(data);
    }
    
    XLAT = 1;
    __delay_ms(10);
    XLAT = 0;
}

void SPIWrite(uint8_t data)
{
    
    // Send
    SSPBUF = data;
    
    // Wait
    while(!SSP1STATbits.BF);
}

void InitApp(void)
{

    /* Setup analog functionality and port direction */
    ANSELA = 0x00;
    ANSELB = 0x00;
    ANSELC = 0x00;

  
    LATA = 0x00;    
    LATB = 0x00;    
    LATC = 0x00;    

    /**
    TRISx registers
    */    
    TRISA = 0x37;
    TRISB = 0xA0;
    TRISC = 0xFF;

    /**
    ANSELx registers
    */   
    ANSELC = 0xCF;
    ANSELB = 0xA0;
    ANSELA = 0x13;

    /**
    WPUx registers
    */ 
    WPUB = 0xF0;
    WPUA = 0x3F;
    WPUC = 0xFF;
    OPTION_REGbits.nWPUEN = 0;

    /**
    ODx registers
    */   
    ODCONA = 0x00;
    ODCONB = 0x00;
    ODCONC = 0x00;
    

    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x00; // unlock PPS

    SSPCLKPPS = 0x0E;   //RB6->MSSP:SCK;
    SSPDATPPS = 0x02;   //RA2->MSSP:SDI;
    RB6PPS = 0x10;   //RB6->MSSP:SCK;
    RB4PPS = 0x11;   //RB4->MSSP:SDO;
    
    ATINPPS = 0x14;   //RC4->AT:ATIN;
    
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x01; // lock PPS
    /* End MCC  */
    
    /* Initialize peripherals */
    OETRIS = 0;
    XLATTRIS = 0;
    
    SPISDOTRIS = 0;   // SDO
    SPISCKTRIS = 0;   // SCK
    
    
    OE = 0;

    //SSPSTAT = 0x40;        // Set SMP=0 and CKE=1. Notes: The lower 6 bit is read only
    //SSPCON1 = 0x20;        // Enable SPI Master with Fosc/4
    
    //SSPSTATbits.CKE = 0;       //Transmit on idle->active clock edge
    
    //SSP1CONbits.SSPEN = 1;
        // R_nW write_noTX; P stopbit_notdetected; S startbit_notdetected; BF RCinprocess_TXcomplete; SMP Middle; UA dontupdate; CKE Idle to Active; D_nA lastbyte_address; 
    SSP1STAT = 0x40;
    
    // SSPEN enabled; WCOL no_collision; CKP Idle:Low, Active:High; SSPM FOSC/4; SSPOV no_overflow; 
    SSP1CON1 = 0x20;
    
    // SSP1ADD 0; 
    SSP1ADD = 0x00;

    /* Configure the IPEN bit (1=on) in RCON to turn on/off int priorities */
    AT_Initialize();
    /* Enable interrupts */
    //INTCONbits.GIE = 1;
    //INTCONbits.PEIE = 1;
}

