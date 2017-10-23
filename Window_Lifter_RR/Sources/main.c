#include "Cpu.h"
#include "pin_mux.h"
#include "clockMan1.h"
#include "S32K144.h"
#include "clocks.h"

volatile int exit_code = 0;
int lpit0_ch0_flag_counter = 0; /* LPIT0 timeout counter */
int counter=-1;

void PORT_init (void);
void LPIT0_init (void);
void WDOG_disable (void);

int main(void)
{/* Write your code here */
	/* Write your local variable definition here */

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
#ifdef PEX_RTOS_INIT
	PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
#endif
	/*** End of Processor Expert internal initialization.                    ***/

	WDOG_disable();
	PORT_init(); /* Configure ports */
	SOSC_init_8MHz(); /* Initialize system oscillator for 8 MHz xtal */
	SPLL_init_160MHz(); /* Initialize sysclk to 160 MHz with 8 MHz SOSC */
	NormalRUNmode_80MHz(); /* Init clocks: 80 MHz sysclk & core, 40 MHz bus, 20 MHz flash */
	LPIT0_init(); /* Initialize PIT0 for 1 second timeout */

	while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
	lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
	PTD->PSOR |= 1<<0; /*  turning off BLUE LED */
	PTD->PSOR |= 1<<15; /* turning off RED LED */
	PTD->PSOR |= 1<<16; /* turning off GREEN LED */
	PTC->PCOR |= 1<<7;/*Turning off the Port 7*/
	PTC->PCOR |= 1<<14;
	PTC->PCOR |= 1<<3;
	PTB->PCOR |= 1<<17;
	PTB->PCOR |= 1<<14;
	PTB->PCOR |= 1<<15;
	PTB->PCOR |= 1<<16;
	PTE->PCOR |= 1<<15;
	PTE->PCOR |= 1<<16;
	PTE->PCOR |= 1<<14;


	LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */

	for (;;) {
		while (PTC->PDIR & (1<<12)){
			PTD->PCOR |= 1<<0;
			if (counter<9) {
						counter++;
					}
			switch (counter) {
				case 0:

			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTC->PSOR |= 1<<7;
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

				case 1:

			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTB->PSOR |= 1<<17; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

				case 2:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTB->PSOR |= 1<<14; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

				case 3:

			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTB->PSOR |= 1<<15; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

				case 4:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTB->PSOR |= 1<<16; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

				case 5:
					while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTC->PSOR |= 1<<14; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */

			break;

				case 6:

			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTC->PSOR |= 1<<3; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

				case 7:

			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTE->PSOR |= 1<<16; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

				case 8:


			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTE->PSOR |= 1<<15; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

				case 9:

			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTD->PSOR |= 1<<0; /* Toggle output on port D0 (blue LED) */
			PTE->PSOR |= 1<<14; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */

			break;


			}

		}


		//SUBIDA CON ONE TOUCH

//		if (PTC->PDIR & (1<<12)) {
//			if (PTC->PDIR | (1<<12)){
//				while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {}
//				lpit0_ch0_flag_counter++;
//				PTD->PCOR |= 1<<0;
//				PTC->PSOR |= 1<<7; /* Toggle output on port D16 (green LED) */
//				LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
//
//
//				while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
//				lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
//				PTB->PSOR |= 1<<17; /* Toggle output on port D0 (blue LED) */
//				LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
//
//				while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
//				lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
//				PTB->PSOR |= 1<<14; /* Toggle output on port D0 (blue LED) */
//				LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
//
//				while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
//				lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
//				PTB->PSOR |= 1<<15; /* Toggle output on port D0 (blue LED) */
//				LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
//
//				while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
//				lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
//				PTB->PSOR |= 1<<16; /* Toggle output on port D0 (blue LED) */
//				LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
//
//				while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
//				lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
//				PTC->PSOR |= 1<<14; /* Toggle output on port D0 (blue LED) */
//				LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
//
//				while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
//				lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
//				PTC->PSOR |= 1<<3; /* Toggle output on port D0 (blue LED) */
//				LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
//
//				while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
//				lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
//				PTE->PSOR |= 1<<16; /* Toggle output on port D0 (blue LED) */
//				LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
//
//				while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
//				lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
//				PTE->PSOR |= 1<<15; /* Toggle output on port D0 (blue LED) */
//				LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
//
//				while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
//				lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
//				PTE->PSOR |= 1<<14; /* Toggle output on port D0 (blue LED) */
//				LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
//
//				while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
//				lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
//				PTD->PSOR |= 1<<0; /* Toggle output on port D0 (blue LED) */
//				LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
//
//			}
//		}

		while(PTC->PDIR & (1<<13)){
			PTD->PCOR |= 1<<16; /* Toggle output on port D16 (green LED) */
			switch (counter) {
				case 9:

			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */

			PTE->PCOR |= 1<<14; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

				case 8:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTE->PCOR |= 1<<15; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

				case 7:

			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTE->PCOR |= 1<<16; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

				case 6:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTC->PCOR |= 1<<3; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

				case 5:

			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTC->PCOR |= 1<<14; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

				case 4:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTB->PCOR |= 1<<16; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

				case 3:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTB->PCOR |= 1<<15; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

				case 2:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTB->PCOR |= 1<<14; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

				case 1:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTB->PCOR |= 1<<17; /* Toggle output on port D0 (blue LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			break;

				case 0:
			while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
			lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
			PTD->PSOR |= 1<<16; /* Toggle output on port D16 (green LED) */
			PTC->PCOR |= 1<<7; /* Toggle output on port D16 (green LED) */
			LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
			counter=-1;
			break;
				default:
					break;
		}
			if (counter>0){
				counter--;
			}
		}

		//BAJADA CON ONE TOUCH EN BOTON IZQUIERO
//		if(PTC->PDIR & (1<<13)){/* If Pad Data Input = 1 (BTN1 [SW3] pushed) */
//			if(PTC->PDIR | (1<<13)){
//
//				while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
//				lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
//				PTD->PCOR |= 1<<16; /* Toggle output on port D16 (green LED) */
//				PTE->PCOR |= 1<<14; /* Toggle output on port D0 (blue LED) */
//				LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
//
//				while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
//				lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
//				PTE->PCOR |= 1<<15; /* Toggle output on port D0 (blue LED) */
//				LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
//
//				while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
//				lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
//				PTE->PCOR |= 1<<16; /* Toggle output on port D0 (blue LED) */
//				LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
//
//				while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
//				lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
//				PTC->PCOR |= 1<<3; /* Toggle output on port D0 (blue LED) */
//				LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
//
//				while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
//				lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
//				PTC->PCOR |= 1<<14; /* Toggle output on port D0 (blue LED) */
//				LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
//
//				while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
//				lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
//				PTB->PCOR |= 1<<16; /* Toggle output on port D0 (blue LED) */
//				LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
//
//				while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
//				lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
//				PTB->PCOR |= 1<<15; /* Toggle output on port D0 (blue LED) */
//				LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
//
//				while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
//				lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
//				PTB->PCOR |= 1<<14; /* Toggle output on port D0 (blue LED) */
//				LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
//
//				while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
//				lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
//				PTB->PCOR |= 1<<17; /* Toggle output on port D0 (blue LED) */
//				LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
//
//				while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
//				lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
//				PTC->PCOR |= 1<<7; /* Toggle output on port D16 (green LED) */
//				LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
//
//				while (0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)) {} /* Wait for LPIT0 CH0 Flag */
//				lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
//				PTD->PSOR |= 1<<16; /* Toggle output on port D16 (green LED) */
//				LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
//			}
//		}
	}
}


void PORT_init (void) {/*Initializing the PORTS*/
	PCC-> PCCn[PCC_PORTD_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */
	PCC-> PCCn[PCC_PORTC_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */
	PCC-> PCCn[PCC_PORTB_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */
	PCC-> PCCn[PCC_PORTE_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */

	PTD->PDDR |= 1<<0; /* Port D0: Data Direction= output */
	PTD->PDDR |= 1<<15; /* Port D15: Data Direction= output */
	PTD->PDDR |= 1<<16; /* Port D16: Data Direction= output */
	PTC->PDDR |= 1<<7;/*Port C7: Data Direction= output*/
	PTB->PDDR |= 1<<17;
	PTB->PDDR |= 1<<14;
	PTB->PDDR |= 1<<15;
	PTB->PDDR |= 1<<16;
	PTC->PDDR |= 1<<14;
	PTC->PDDR |= 1<<3;
	PTE->PDDR |= 1<<15;
	PTE->PDDR |= 1<<16;
	PTE->PDDR |= 1<<14;
	PTC->PDDR &= ~(1<<12);/*PORT C12: Data Direction= input*/
	PTC->PDDR &= ~(1<<13);/*PORT C13: Data Direction= input*/

	PORTD->PCR[0]  = 0x00000100; /* Port D0: MUX = ALT1, GPIO (to blue LED on EVB) */
	PORTD->PCR[15] = 0x00000100; /* Port D0: MUX = ALT1, GPIO (to red LED on EVB) */
	PORTD->PCR[16] = 0x00000100; /* Port D0: MUX = ALT1, GPIO (to green LED on EVB) */
	PORTC->PCR[7] = 0x00000100;
	PORTB->PCR[17] = 0x00000100;
	PORTB->PCR[14] = 0x00000100;
	PORTB->PCR[15] = 0x00000100;
	PORTB->PCR[16] = 0x00000100;
	PORTC->PCR[14] = 0x00000100;
	PORTC->PCR[3] = 0x00000100;
	PORTE->PCR[15] = 0x00000100;
	PORTE->PCR[16] = 0x00000100;
	PORTE->PCR[14] = 0x00000100;
	PORTC->PCR[12] = 0x00000110;
	PORTC->PCR[13] = 0x00000110;
}

void LPIT0_init (void) {
	PCC->PCCn[PCC_LPIT_INDEX] = PCC_PCCn_PCS(6); /* Clock Src = 6 (SPLL2_DIV2_CLK)*/
	PCC->PCCn[PCC_LPIT_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable clk to LPIT0 regs */
	LPIT0->MCR = 0x00000001; /* DBG_EN-0: Timer chans stop in Debug mode */
	//LPIT0->MCR = 0x00000100; /* DBG_EN-0: Timer chans stop in Debug mode */
	/* DOZE_EN=0: Timer chans are stopped in DOZE mode */
	/* SW_RST=0: SW reset does not reset timer chans, regs */
	/* M_CEN=1: enable module clk (allows writing other LPIT0 regs)*/
	LPIT0->TMR[0].TVAL = 16000000; /* Chan 0 Timeout period: 20M clocks */
	//LPIT0->TMR[1].TVAL = 40000000;
	LPIT0->TMR[0].TCTRL = 0x00000001; /* T_EN=1: Timer channel is enabled */
	//LPIT0->TMR[1].TCTRL = 0x00000001;
	/* CHAIN=0: channel chaining is disabled */
	/* MODE=0: 32 periodic counter mode */
	/* TSOT=0: Timer decrements immediately based on restart */
	/* TSOI=0: Timer does not stop after timeout */
	/* TROT=0 Timer will not reload on trigger */
	/* TRG_SRC=0: External trigger source */
	/* TRG_SEL=0: Timer chan 0 trigger source is selected*/
}

void WDOG_disable (void){
	WDOG->CNT=0xD928C520; /*Unlock watchdog*/
	WDOG->TOVAL=0x0000FFFF; /*Maximum timeout value*/
	WDOG->CS = 0x00002100; /*Disable watchdog*/
}

