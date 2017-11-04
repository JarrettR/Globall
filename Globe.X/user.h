/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/
#include "system.h" 

#define SPISDOTRIS      TRISBbits.TRISB4
#define SPISCKTRIS      TRISBbits.TRISB6

#define OE          LATBbits.LATB5
#define OETRIS      TRISBbits.TRISB5
#define XLAT        LATCbits.LATC2
#define XLATTRIS    TRISCbits.TRISC2

#define TABLESIZE 36
#define CHANNELS  24

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/
void setChannel(uint8_t *, uint8_t , uint16_t );
void LEDMap(uint8_t *);
void SPIWrite(uint8_t);
void InitApp(void);         /* I/O and Peripheral Initialization */
