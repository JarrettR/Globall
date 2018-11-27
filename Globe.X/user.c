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



/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/
void setChannel(uint8_t *blob, uint8_t channel, uint16_t value) {
    uint8_t lvalue;
    uint8_t rvalue;
    uint8_t newVal;
    uint8_t byteAddr;
    
    if(channel % 2 == 0) {
        byteAddr = (channel * 3) >> 1;
        lvalue = (uint8_t)(value & 0xFF);
        rvalue = (uint8_t)(value >> 8);
        
        *(blob + byteAddr) = lvalue;
        newVal = (*(blob + byteAddr + 1)) & 0xF0;
        newVal = rvalue | newVal;
        
        *(blob + byteAddr + 1) = newVal;
    } else { //channel % 2 == 1
        byteAddr = (((channel - 1) * 3) >> 1) + 1;
        
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
    
    XLAT1_SetLow();
    
    for(int i = TABLESIZE - 1; i >= 0; i--) {
        data = *(blob + i);
        SPIWrite(data);
        //SPIWrite(0xFF & i);
    }
    
    XLAT1_SetHigh();
    __delay_us(1);
    XLAT1_SetLow();
}

void LEDSingle(uint8_t address)
{
    uint8_t data = 0;
    
    XLAT1_SetLow();
    
    for(int i = TABLESIZE - 1; i >= 0; i--) {
        if(i == address) {
            SPIWrite(0x00);
        } else {
            SPIWrite(0xFF);
        }
    }
    
    XLAT1_SetHigh();
    __delay_ms(10);
    XLAT1_SetLow();
}

void SPIWrite(uint8_t data)
{
    
    // Send
    //SSPBUF = data;
    
    // Wait
    //while(!SSP1STATbits.BF);
    SPI_Exchange8bit(data);
}

inline void EnableInterrupts(void) {
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
}

inline void DisableInterrupts(void) {
    INTCONbits.GIE = 0;
    INTCONbits.PEIE = 0;
}
