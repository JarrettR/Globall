#ifndef _AT_H
#define _AT_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>


unsigned int angleInt = 0;

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
void AT_MissingPulseDelaySet(int16_t  missingPulse);

/**
  @Summary
    Load threshold period for error calculation 

  @Description
    Set the acceptable threshold point for the period

  @Preconditions
    None

  @Param
    Pass 16 bit set point

  @Returns
    None

  @Example
    <code>
    
    </code>
*/
void AT_SetPointLoad(uint16_t thresholdPeriod);
        
/**
  @Summary
    Read measured period count

  @Description    
    Read the measured period count
 * 
  @Preconditions
    None

  @Param
    None

  @Returns
    Return 15 bit period count 

  @Example
    <code>
    
    </code>
*/
uint16_t AT_PeriodGet(void);

/**
  @Summary
    Read measured phase count

  @Description    
    Read measured phase count

  @Preconditions
    None

  @Param
    None

  @Returns
    Return 10 bit Phase count

  @Example
    <code>
    
    </code>
*/
uint16_t AT_PhaseGet(void);

/**
  @Summary
    Read error of the measured period value compared to the threshold setting (ATxPER â?? ATxSTP = ATxERR)

  @Description    
    Read calculated error from the difference of period with set point

  @Preconditions
    None

  @Param
    None

  @Returns
    Return 16 bit error count

  @Example
    <code>
    
    </code>
*/
int16_t AT_SetPointErrorGet(void);

/**
  @Summary
    Returns comparison result of current period value with previous value.

  @Description    
    Compares with the previous value of period register and displays result as less than or greater than 	

  @Preconditions
    None

  @Param
    None

  @Returns
    true - The value currently in AT1PER is less than the previous value
    false - The value currently in AT1PER is greater than or equal to the previous value

  @Example
    <code>
    
    </code>
*/
bool AT_CheckPeriodValue(void);

/**
  @Summary
    Returns status after verifying ATxPER(period) and ATxPHS(phase) input cycles.

  @Description    
    Confirms weather result obtained in period and phase registers are valid of invalid

  @Preconditions
    None

  @Param
    None

  @Returns
    true - valid input cycles
    false - Invalid input cycles( not enough input cycles)

  @Example
    <code>
    
    </code>
*/
bool AT_IsMeasurementValid(void);

/**
  @Summary
    Returns status of ATxPER(period counter).

  @Description    
    Confirms if the result obtained in period register is rolled over or not

  @Preconditions
    None

  @Param
    None

  @Returns
    true - Counter rolled over one or more times during measurement
    false - Value shown by ATxPER is valid

  @Example
    <code>
    
    </code>
*/
bool AT_IsPeriodCounterOverflowOccured(void);

/**
  @Summary
    Returns status of Phase interrupt flag bit (PHSIF ).

  @Description    
    Calculated phase count will be available in this register

  @Preconditions
    None

  @Param
    None

  @Returns
    true - phase count is available in register
    false - phase count is not available

  @Example
    <code>
    
    </code>
*/
bool AT_IsPhaseCountAvailable(void);

/**
  @Summary
    Returns status of Missed Pulse interrupt flag bit (MSSIF ).

  @Description
    

  @Preconditions
    None

  @Param
    None

  @Returns
    true -  Missing pulse count is available
    false - Missing pulse count is not available

  @Example
    <code>
    
    </code>
*/
bool AT_IsMissedPulseCountAvailable(void);

/**
  @Summary
    Returns status of Period interrupt flag bit (PERIF )

  @Description
     

  @Preconditions
    None

  @Param
    None

  @Returns
    true - Period count available
    false - Period count not available

  @Example
    <code>
    
    </code>
*/
bool AT_IsPeriodCountAvailable(void);







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
