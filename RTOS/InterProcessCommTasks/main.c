/*
 * FreeRTOS Kernel V10.2.0
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/* 
	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used.
*/


/*
 * Creates all the demo application tasks, then starts the scheduler.  The WEB
 * documentation provides more details of the demo application tasks.
 * 
 * Main.c also creates a task called "Check".  This only executes every three 
 * seconds but has the highest priority so is guaranteed to get processor time.  
 * Its main function is to check that all the other tasks are still operational.
 * Each task (other than the "flash" tasks) maintains a unique count that is 
 * incremented each time the task successfully completes its function.  Should 
 * any error occur within such a task the count is permanently halted.  The 
 * check task inspects the count of each task to ensure it has changed since
 * the last time the check task executed.  If all the count variables have 
 * changed all the tasks are still executing error free, and the check task
 * toggles the onboard LED.  Should any task contain an error at any time 
 * the LED toggle rate will change from 3 seconds to 500ms.
 *
 */

/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "lpc21xx.h"

/* Peripheral includes. */
#include "GPIO.h"

/* External includes. */
#include "InterProcessCommTasks.h"

/*-----------------------------------------------------------*/

/* Constants to setup I/O and processor. */
#define mainBUS_CLK_FULL	( ( unsigned char ) 0x01 )

/* Constants for the ComTest demo application tasks. */
#define mainCOM_TEST_BAUD_RATE	( ( unsigned long ) 115200 )

/* Task Handler declarations */

#if PROBLEM1

TaskHandle_t LedToggleHandler = NULL;
SemaphoreHandle_t xSemaphore;

#endif

#if PROBLEM2

TaskHandle_t vWriteStrHandler100  = NULL;
TaskHandle_t vWriteStrHandler500  = NULL;

#endif

#if PROBLEM3

TaskHandle_t ButtonCheck1_Handler = NULL;
TaskHandle_t ButtonCheck2_Handler = NULL;
TaskHandle_t ConsumerTask_Handler = NULL;
TaskHandle_t SendString_Handler   = NULL;
QueueHandle_t xQueue;
struct AMessage xMessage100 = {"| 100ms String| "};

#endif

/*
 * Configure the processor for use with the Keil demo board.  This is very
 * minimal as most of the setup is managed by the settings in the project
 * file.
 */
static void prvSetupHardware( void );
/*-----------------------------------------------------------*/


/*
 * Application entry point:
 * Starts all the other tasks, then starts the scheduler. 
 */
int main( void )
{
	/* Setup the hardware for use with the Keil demo board. */
	prvSetupHardware();
	
	/* Initially, turn off the used leds on P0.0, P0.3 */
	GPIO_write(PORT_0, PIN0, PIN_IS_LOW);
	GPIO_write(PORT_0, PIN3, PIN_IS_LOW);
	
	#if PROBLEM1
	
	  xSemaphore = xSemaphoreCreateBinary();

    if( xSemaphore == NULL )
    {
        /* Used fro Debugging in case of the creation failed */
    }
		
    /* Create tasks, storing the handlers. */
    xTaskCreate(
                    vLedToggle,      			/* Function that implements the task. */
                    "Led Toggle",   		  /* Text name for the task. */
                    50,      					    /* Stack size in words, not bytes. */
                    ( void * ) 0,   		  /* Parameter passed into the task. */
                    1,							 			/* Priority at which the task is created. */
                    &LedToggleHandler );  /* Used to pass out the created task's handle. */
										
	  xTaskCreate(
                    vButtonCheck,      		/* Function that implements the task. */
                    "Button Check",   		/* Text name for the task. */
                    50,      					    /* Stack size in words, not bytes. */
                    ( void * ) 0,   		  /* Parameter passed into the task. */
                    1,							 			/* Priority at which the task is created. */
                    &LedToggleHandler );  /* Used to pass out the created task's handle. */
										
										

	
	#endif

	#if PROBLEM2

	/* Create tasks, storing the handlers. */
    xTaskCreate(
                    vWriteStr100,     	  	 /* Function that implements the task. */
                    "Write String100",       /* Text name for the task. */
                    60,      			 					 /* Stack size in words, not bytes. */
                    ( void * ) 0,   	 	  	 /* Parameter passed into the task. */
                    1,				 							 /* Priority at which the task is created. */
                    &vWriteStrHandler100 );  /* Used to pass out the created task's handle. */
										
										
    xTaskCreate(
                    vWriteStr500,    	  	   /* Function that implements the task. */
                    "Write String500",   	   /* Text name for the task. */
                    60,      			 			 	 	 /* Stack size in words, not bytes. */
                    ( void * ) 0,    			   /* Parameter passed into the task. */
                    1,				 							 /* Priority at which the task is created. */
                    &vWriteStrHandler500 );  /* Used to pass out the created task's handle. */																			  
	
	#endif
	
	#if PROBLEM3
	 
	 /* Create queue with 1 element and size of AMessage structure */
	 xQueue = xQueueCreate( 1, sizeof( xMessage100 ) );
	 
	 if(xQueue == NULL)
	 {
			/* Used for debugging in case of queue creation failure */
	 }
	 
	 /* Create tasks, storing the handlers. */									
	 xTaskCreate(  
                    vButtonCheck1,      		           /* Function that implements the task. */
                    "Button Check1",    		           /* Text name for the task. */
                    50,      			 		 		 	         /* Stack size in words, not bytes. */
                    ( void * ) 0,    		 		         /* Parameter passed into the task. */
                    1,		 		 								       /* Priority at which the task is created. */
																							       // The highe priority for button checking
                    &ButtonCheck1_Handler ); 	       /* Used to pass out the created task's handle. */
										
	 xTaskCreate(
                    vButtonCheck2,      		     /* Function that implements the task. */
                    "Button Check2",    		     /* Text name for the task. */
                    50,      			 		 		 	 			   /* Stack size in words, not bytes. */
                    ( void * ) 0,    		 					   /* Parameter passed into the task. */
                    1,		 		 										   /* Priority at which the task is created. */
                    &ButtonCheck2_Handler );   /* Used to pass out the created task's handle. */
										
	xTaskCreate(
                    vConsumerTask,      		   /* Function that implements the task. */
                    "Consumer Task",    		   /* Text name for the task. */
                    150,      			 		 		        	 /* Stack size in words, not bytes. */
                    ( void * ) 0,    		 	        	 /* Parameter passed into the task. */
                    1,		 		                       /* Priority at which the task is created. */
                    &ConsumerTask_Handler ); /* Used to pass out the created task's handle. */
										
  xTaskCreate(
                    vSendString100,      		  /* Function that implements the task. */
                    "Send String100",    		    /* Text name for the task. */
                    50,      			 		 		 	          /* Stack size in words, not bytes. */
                    ( void * ) 0,    		 		          /* Parameter passed into the task. */
                    1,		 		                        /* Priority at which the task is created. */
                    &SendString_Handler ); /* Used to pass out the created task's handle. */
										
	
	#endif
										
	/* Now all the tasks have been started - start the scheduler.

	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used here. */
	vTaskStartScheduler();

	/* Should never reach here!  If you do then there was not enough heap
	available for the idle task to be created. */
	for( ;; );
}
/*-----------------------------------------------------------*/

static void prvSetupHardware( void )
{
	/* Perform the hardware setup required.  This is minimal as most of the
	setup is managed by the settings in the project file. */

	/* Configure UART */
	xSerialPortInitMinimal(mainCOM_TEST_BAUD_RATE);

	/* Configure GPIO */
	GPIO_init();

	/* Setup the peripheral bus to be the same as the PLL output. */
	VPBDIV = mainBUS_CLK_FULL;
}
/*-----------------------------------------------------------*/


