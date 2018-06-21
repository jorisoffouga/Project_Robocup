/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : Cpu.c
**     Project     : Robocup_SSL
**     Processor   : MC9S08QE16CLC
**     Component   : MC9S08QE32_32
**     Version     : Component 01.005, Driver 01.40, CPU db: 3.00.027
**     Datasheet   : MC9S08QE32RM Rev. 3 Draft A 11/2009
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2018-06-21, 09:41, # CodeGen: 33
**     Abstract    :
**         This component "MC9S08QE32_32" contains initialization 
**         of the CPU and provides basic methods and events for 
**         CPU core settings.
**     Settings    :
**
**     Contents    :
**         EnableInt  - void Cpu_EnableInt(void);
**         DisableInt - void Cpu_DisableInt(void);
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
** @file Cpu.c
** @version 01.40
** @brief
**         This component "MC9S08QE32_32" contains initialization 
**         of the CPU and provides basic methods and events for 
**         CPU core settings.
*/         
/*!
**  @addtogroup Cpu_module Cpu module documentation
**  @{
*/         

/* MODULE Cpu. */

#pragma MESSAGE DISABLE C4002 /* WARNING C4002: Result not used is ignored */

#include "SCI1.h"
#include "CI2C1.h"
#include "TPM1.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Events.h"
#include "Cpu.h"


/* Global variables */
volatile byte CCR_reg;                 /* Current CCR register */
volatile byte CCR_lock;                /* Nesting level of critical regions */


/*
** ===================================================================
**     Method      :  Cpu_Interrupt (component MC9S08QE32_32)
**
**     Description :
**         The method services unhandled interrupt vectors.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(Cpu_Interrupt)
{
  /* This code can be changed using the CPU component property "Build Options / Unhandled int code" */
  /*lint -save -e950 Disable MISRA rule (1.1) checking. */
  asm(BGND);
  /*lint -restore Enable MISRA rule (1.1) checking. */
}


/*
** ===================================================================
**     Method      :  Cpu_DisableInt (component MC9S08QE32_32)
**     Description :
**         Disables maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_DisableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_EnableInt (component MC9S08QE32_32)
**     Description :
**         Enables maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_EnableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  _EntryPoint (component MC9S08QE32_32)
**
**     Description :
**         Initializes the whole system like timing and so on. At the end 
**         of this function, the C startup is invoked to initialize stack,
**         memory areas and so on.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
extern void _Startup(void);            /* Forward declaration of external startup function declared in file Start12.c */

#pragma NO_FRAME
#pragma NO_EXIT
void _EntryPoint(void)
{
  /* ### MC9S08QE32_32 "Cpu" init code ... */
  /*  PE initialization code after reset */
  /* Common initialization of the write once registers */
  /* SOPT1: COPE=0,COPT=1,STOPE=0,??=0,??=0,??=0,BKGDPE=1,RSTPE=0 */
  setReg8(SOPT1, 0x42U);                
  /* SOPT2: COPCLKS=0,??=0,??=0,SPIFE=1,SPIPS=0,ACIC2=0,IICPS=0,ACIC1=0 */
  setReg8(SOPT2, 0x10U);                
  /* SPMSC1: LVDF=0,LVDACK=0,LVDIE=0,LVDRE=1,LVDSE=1,LVDE=1,??=0,BGBE=0 */
  setReg8(SPMSC1, 0x1CU);               
  /* SPMSC2: LPR=0,LPRS=0,LPWUI=0,??=0,PPDF=0,PPDACK=0,PPDE=1,PPDC=0 */
  setReg8(SPMSC2, 0x02U);               
  /* SPMSC3: LVDV=0,LVWV=0,LVWIE=0 */
  clrReg8Bits(SPMSC3, 0x38U);           
  /*  System clock initialization */
  /*lint -save  -e923 Disable MISRA rule (11.3) checking. */
  if (*(uint8_t*)0xFFAFU != 0xFFU) {   /* Test if the device trim value is stored on the specified address */
    ICSTRM = *(uint8_t*)0xFFAFU;       /* Initialize ICSTRM register from a non volatile memory */
    ICSSC = (uint8_t)((*(uint8_t*)0xFFAEU) & (uint8_t)0x01U); /* Initialize ICSSC register from a non volatile memory */
  }
  /*lint -restore Enable MISRA rule (11.3) checking. */
  /* ICSC1: CLKS=0,RDIV=0,IREFS=0,IRCLKEN=1,IREFSTEN=0 */
  setReg8(ICSC1, 0x02U);               /* Initialization of the ICS control register 1 */ 
  /* ICSC2: BDIV=0,RANGE=0,HGO=0,LP=0,EREFS=0,ERCLKEN=1,EREFSTEN=0 */
  setReg8(ICSC2, 0x02U);               /* Initialization of the ICS control register 2 */ 
  /* ICSSC: DRST_DRS=2,DMX32=0 */
  clrSetReg8Bits(ICSSC, 0x60U, 0x80U); /* Initialization of the ICS status and control */ 
  while((ICSSC & 0xC0U) != 0x80U) {    /* Wait until the FLL switches to High range DCO mode */
  }

  /*** End of PE initialization code after reset ***/
  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */
  __asm   jmp _Startup ;               /* Jump to C startup code */
  /*lint -restore Enable MISRA rule (1.1) checking. */
}

/*
** ===================================================================
**     Method      :  PE_low_level_init (component MC9S08QE32_32)
**
**     Description :
**         Initializes components and provides common register 
**         initialization. The method is called automatically as a part 
**         of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PE_low_level_init(void)
{
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /* SCGC1: TPM3=1,TPM2=1,TPM1=1,ADC=1,??=1,IIC=1,SCI2=1,SCI1=1 */
  setReg8(SCGC1, 0xFFU);                
  /* SCGC2: DBG=1,FLS=1,IRQ=1,KBI=1,ACMP=1,RTC=1,??=1,SPI=1 */
  setReg8(SCGC2, 0xFFU);                
  /* Common initialization of the CPU registers */
  /* PTADD: PTADD3=0,PTADD2=0 */
  clrReg8Bits(PTADD, 0x0CU);            
  /* PTASE: PTASE7=0,PTASE6=0,PTASE4=0,PTASE3=0,PTASE2=0,PTASE1=0,PTASE0=0 */
  clrReg8Bits(PTASE, 0xDFU);            
  /* PTBSE: PTBSE7=0,PTBSE6=0,PTBSE5=0,PTBSE4=0,PTBSE3=0,PTBSE2=0,PTBSE1=0,PTBSE0=0 */
  setReg8(PTBSE, 0x00U);                
  /* PTCSE: PTCSE7=0,PTCSE6=0,PTCSE5=0,PTCSE4=0,PTCSE3=0,PTCSE2=0,PTCSE1=0,PTCSE0=0 */
  setReg8(PTCSE, 0x00U);                
  /* PTDSE: PTDSE3=0,PTDSE2=0,PTDSE1=0,PTDSE0=0 */
  clrReg8Bits(PTDSE, 0x0FU);            
  /* PTADS: PTADS7=1,PTADS6=1,PTADS5=0,PTADS4=1,PTADS3=1,PTADS2=1,PTADS1=1,PTADS0=1 */
  setReg8(PTADS, 0xDFU);                
  /* PTBDS: PTBDS7=1,PTBDS6=1,PTBDS5=1,PTBDS4=1,PTBDS3=1,PTBDS2=1,PTBDS1=1,PTBDS0=1 */
  setReg8(PTBDS, 0xFFU);                
  /* PTCDS: PTCDS7=1,PTCDS6=1,PTCDS5=1,PTCDS4=1,PTCDS3=1,PTCDS2=1,PTCDS1=1,PTCDS0=1 */
  setReg8(PTCDS, 0xFFU);                
  /* PTDDS: PTDDS7=0,PTDDS6=0,PTDDS5=0,PTDDS4=0,PTDDS3=1,PTDDS2=1,PTDDS1=1,PTDDS0=1 */
  setReg8(PTDDS, 0x0FU);                
  /* PTDDD: PTDDD7=1,PTDDD6=1,PTDDD5=1,PTDDD4=1 */
  setReg8Bits(PTDDD, 0xF0U);            
  /* PTEDD: PTEDD7=1,PTEDD6=1,PTEDD5=1,PTEDD4=1,PTEDD3=1,PTEDD2=1,PTEDD1=1,PTEDD0=1 */
  setReg8(PTEDD, 0xFFU);                
  /* ### Shared modules init code ... */
  /* ### Init_SCI "SCI1" init code ... */
  /* ### Call "SCI1_Init();" init method in a user code, i.e. in the main code */
  /* ### Note:   To enable automatic calling of the "SCI1" init code here must be
                 set the property Call Init method to 'yes'.
   */
  /* ### InternalI2C "CI2C1" init code ... */
  CI2C1_Init();
  /* ### Init_TPM "TPM1" init code ... */
  /* ### Call "TPM1_Init();" init method in a user code, i.e. in the main code */
  /* ### Note:   To enable automatic calling of the "TPM1" init code here must be
                 set the property 'Call Init method' to 'yes'
   */
  CCR_lock = (byte)0;
  __EI();                              /* Enable interrupts */
}

/*lint -save  -e950 Disable MISRA rule (1.1) checking. */
/* Initialization of the CPU registers in FLASH */
/* NVPROT: FPS7=1,FPS6=1,FPS5=1,FPS4=1,FPS3=1,FPS2=1,FPS1=1,FPDIS=1 */
static const uint8_t NVPROT_INIT @0x0000FFBDU = 0xFFU;
/* NVOPT: KEYEN=0,FNORED=1,??=1,??=1,??=1,??=1,SEC01=1,SEC00=0 */
static const uint8_t NVOPT_INIT @0x0000FFBFU = 0x7EU;
/*lint -restore Enable MISRA rule (1.1) checking. */

/* END Cpu. */

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
