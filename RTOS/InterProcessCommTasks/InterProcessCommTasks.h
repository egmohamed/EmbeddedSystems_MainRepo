#ifndef __TOGGLE_TASKS_H
#define __TOGGLE_TASKS_H

/* Inter process communication headers */
#include "semphr.h"
#include "serial.h"
#include "queue.h"

/* Standard ON/OFF declarations */
#define STD_ON			1U
#define STD_OFF			0U

/* Choose one of problems to enable */
#define PROBLEM1 		STD_OFF
#define PROBLEM2 		STD_OFF
#define PROBLEM3 		STD_ON

#if PROBLEM1

/*---- vLedToggle Task Description ---------------------------------
*
*   Task executes every 1ms, trying to get the semaphore. When the 
*	Task successfully get the semaphore, it toggles the led on
*	P0.0 otherwise task is blocked
*
*-------------------------------------------------------------------*/
void vLedToggle	 ( void * pvParameters );

/*---- vButtonCheck Task Description --------------------------------
*
*   Task executes every 1ms. Continiously check for 
*	the button state change to give the semaphore to vLedToggle task
*
*-------------------------------------------------------------------*/
void vButtonCheck( void * pvParameters );

/* Extern Handlers */
extern SemaphoreHandle_t xSemaphore;

#endif

#if PROBLEM2

/*---- vWriteStr500 Task Description -------------------------------
*
*   Task executes every 0.5s. The task will write a string 10 times
*	every 500ms
*
*-------------------------------------------------------------------*/
void vWriteStr500( void * pvParameters );

/*---- vWriteStr100 Task Description -------------------------------
*
*   Task executes every 0.1s. The task will write a string 10 times
*		every 100ms with overload of 100000 operations. Since the task
*		writes a string every 100ms, 10 times per period and the second
*		task will execute in the next 500ms, Then its expected for this 
*		task to print 50 string every 0.5s.
*
*-------------------------------------------------------------------*/
void vWriteStr100( void * pvParameters );

/* Extern Handlers */
extern SemaphoreHandle_t Str1Semaphore;
extern SemaphoreHandle_t Str2Semaphore;

#endif

#if PROBLEM3

/* Symbols to discriminate among vButtonCheck1 task & vButtonCheck2 task */
#define TASK2		3
#define TASK1		1

/* Structure with data to be send through queue */
struct AMessage
{
  signed char ucData[ 17 ];
};

/*---- vButtonCheck1 Task Description --------------------------------
*
*   Detect rising or falling edge on P0.1 Button  
*
*-------------------------------------------------------------------*/
void vButtonCheck1 ( void * pvParameters );

/*---- vButtonCheck1 Task Description --------------------------------
*
*   Detect rising or falling edge on P0.2 Button  
*
*-------------------------------------------------------------------*/
void vButtonCheck2 ( void * pvParameters );

/*---- vConsumerTask Task Description --------------------------------
*
*   Send the received data from other tasks through the UART  
*
*-------------------------------------------------------------------*/
void vConsumerTask ( void * pvParameters );

/*---- vSendString100 Task Description --------------------------------
*
*   Periodically, Send arbitary string every 0.1s to consumer task  
*
*-------------------------------------------------------------------*/
void vSendString100( void * pvParameters );	

/* Extern Handlers */
extern TaskHandle_t ConsumerTask_Handler;
extern QueueHandle_t xQueue;



#endif 

#endif /* __TOGGLE_TASKS_H */
