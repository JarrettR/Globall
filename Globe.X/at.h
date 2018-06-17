#ifndef _AT_H
#define _AT_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>


volatile unsigned int angleInt = 0;

void AT_Initialize(void);

/**
  @Summary
    Load the required 10bit Phase counter resolution 

  @Description
    Set the required resolution for the incoming signal

  @Preconditions
    None

  @Param
    Pass 10 bit Phase counter resolution 

  @Returns
    None

  @Example
    <code>
    
    </code>
*/
void AT_ResolutionSet(uint16_t resolution);

/**
  @Summary
    Load required 15 bit missing pulse delay

  @Description
    In multiple pulse mode. set the expected missing pulses

  @Preconditions
    None

  @Param
    Pass 15 bit missing pulse delay

  @Returns
    None

  @Example
    <code>
    
    </code>
*/



/**
  @Summary
    Check which particular interrupt has occurred and call that function.

  @Description
    This routine is used to implement the ISR for the interrupt-driven
    implementations.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
inline void AT_ISR(void);


/**
  @Summary	
    Clears Period interrupt flag.

  @Description
    This routine is used to implement the ISR for the interrupt-driven
    implementations.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
inline void AT_Period(void);


/**
  @Summary	
    Clears Phase interrupt flag.

  @Description
    This routine is used to implement the ISR for the interrupt-driven
    implementations.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
inline void AT_Phase(void);





#endif	/* AT1_H */
