/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/
  
#define TABLESIZE 36
#define CHANNELS  24

#include "mcc_generated_files/mcc.h" 

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/
void setChannel(uint8_t *, uint8_t , uint16_t );
void LEDMap(uint8_t *);
void SPIWrite(uint8_t);
void LEDSingle(uint8_t);
inline void EnableInterrupts(void);
inline void DisableInterrupts(void);
