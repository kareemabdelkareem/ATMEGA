/*
 * Timer_conf.h
 *
 * Created: 3/1/2023 1:41:46 PM
 *  Author: PC
 */ 


#ifndef TIMER_CONF_H_
#define TIMER_CONF_H_


/****************************************************************/
/** !comment : Please Enter the timer_mode Reference				*/
/** 		   TIMER0_MODE can be : 						*/
/*					    					NORMAL 				*/
/*						    				PWM_PhaseCorrect 				*/
/*							    			CTC 			*/
/*                                      PWM_FastMode           */
/****************************************************************/
#define TIMER0_MODE 		NORMAL




/****************************************************************/
/** !comment : Please Enter the TIMER0_PRESCALER Reference				*/
/** 		   TIMER0_PRESCALER can be : 						*/
/*

											T0_Disable  ,
											F_CPU_Prescaler1,
											F_CPU_Prescaler8,
											F_CPU_Prescaler64,
											F_CPU_Prescaler256,
											F_CPU_Prescaler1024,
											F_T0_PIN_SRISING, */
/****************************************************************/

#define TIMER0_PRESCALER  	 F_CPU_Prescaler1024



/****************************************************************/
/** !comment : Please Enter the timer_mode Reference				*/
/** 		   TIMER0_MODE can be : 						*/
/*									CMP_Disable ,
									NonPWM_Toggle ,
									NonPwm_Clear ,
									NonPwm_Set  ,
									PwmFast_Invert  ,
									PwmFast_NonInvert ,
									PwmPhaseCorrect_UpClear   ,
									PwmPhaseCorrect_Upset ,    */
/****************************************************************/
#define TIMER0_COM_EVENT	 CMP_Disable

/****************************************************************/
/** !comment : Please Enter the timer_mode Reference				*/
/** 		   TIMER0_MODE can be : 						*/
/*					    			T0_INTERRUPT_DISABLE,
									T0_TOV_INTERRUPT_ENABLE,
									T0_OCM_INTERRUPT_ENABLE,
									T0_TOV_OCM_INTERRUPT_ENABLE   */ 
/****************************************************************/
#define Int_State			 T0_TOV_INTERRUPT_ENABLE




#endif /* TIMER_CONF_H_ */