/**
  AT Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    at.h

  @Summary
    This is the generated driver implementation file for the AT driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for AT.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1619
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB             :  MPLAB X 4.15
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

/**
  Section: Included Files
*/

#ifndef AT_H
#define AT_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "../user.h"

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: ADC Module APIs
*/

/**
  @Summary
    Initializes the AT

  @Description
    This routine initializes the Initializes the AT.
    This routine must be called before any other AT routine is called.
    This routine should only be called once during system initialization.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment


  @Example
    <code>
    
    </code>
*/
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
    Read error of the measured period value compared to the threshold setting (ATxPER - ATxSTP = ATxERR)

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
void AT_ISR(void);

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
void AT_Period(void);

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
void AT_Phase(void);





#endif	/* AT1_H */
/**
 End of File
*/