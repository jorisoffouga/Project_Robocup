/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : TPM1.h
**     Project     : Robocup_SSL
**     Processor   : MC9S08QE16CLC
**     Component   : Init_TPM
**     Version     : Component 01.084, Driver 01.20, CPU db: 3.00.027
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2018-06-22, 12:58, # CodeGen: 35
**     Abstract    :
**          This file implements the TPM (TPM1) module initialization
**          according to the Peripheral Initialization Component settings,
**          and defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : TPM1
**          Device                                         : TPM1
**          Settings                                       : 
**            Clock settings                               : 
**              Clock source select                        : Bus rate clock
**              Prescaler                                  : 128
**              Modulo counter                             : 6000
**              Period                                     : 30.522 ms
**            Channels                                     : 0
**          Pins                                           : 
**            External clock source                        : Disabled
**          Interrupts                                     : 
**            Overflow Interrupt                           : 
**              Interrupt                                  : Vtpm1ovf
**              Overflow Interrupt                         : Enabled
**              ISR name                                   : isr_update
**          Initialization                                 : 
**            Call Init method                             : no
**            Enable module                                : yes
**     Contents    :
**         Init - void TPM1_Init(void);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file TPM1.h
** @version 01.20
** @brief
**          This file implements the TPM (TPM1) module initialization
**          according to the Peripheral Initialization Component settings,
**          and defines interrupt service routines prototypes.
*/         
/*!
**  @addtogroup TPM1_module TPM1 module documentation
**  @{
*/         

#ifndef __TPM1
#define __TPM1

/* MODULE TPM1. */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/*
** ===================================================================
**     Method      :  TPM1_Init (component Init_TPM)
**     Description :
**         This method initializes registers of the TPM module
**         according to this Peripheral Initialization settings. Call
**         this method in the user code to initialize the module. By
**         default, the method is called by PE automatically; see "Call
**         Init method" property of the component for more details.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TPM1_Init(void);

/*
** ===================================================================
** The interrupt service routine must be implemented by user in one
** of the user modules (see TPM1.c file for more information).
** ===================================================================
*/
__interrupt void isr_update(void);

/* END TPM1. */

#endif /* ifndef __TPM1 */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
