#ifndef __TOGGLE_TASKS_H
#define __TOGGLE_TASKS_H

/* Standard ON/OFF declarations */
#define STD_ON			1U
#define STD_OFF			0U

/* Choose one of problems to enable */
#define PROBLEM1 		STD_OFF
#define PROBLEM2 		STD_OFF
#define PROBLEM3 		STD_ON

#if PROBLEM1

void vLedToggle	( void * pvParameters );

#endif

#if PROBLEM2

void vLedToggle100 	( void * pvParameters );
void vLedToggle500 	( void * pvParameters );
void vLedToggle1000 ( void * pvParameters );

#endif

#if PROBLEM3

void vButtonCheck					( void * pvParameters );
void vLedOffZeroPlusSec		( void * pvParameters );
void vLedToggleTwoPlusSec ( void * pvParameters );	
void vLedToggleFourPlusSec( void * pvParameters );

#endif 

#endif /* __TOGGLE_TASKS_H */
