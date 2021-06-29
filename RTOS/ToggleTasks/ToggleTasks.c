/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Peripheral includes. */
#include "GPIO.h"

/* Module includes */
#include "ToggleTasks.h"

#if PROBLEM3

/* Module Global variables definition */
static signed long counter  = 0;

static unsigned char Task1 = 0;
static unsigned char Task2 = 0;
static unsigned char Task3 = 0;

#endif

/* Problem 1 Tasks */
/* preemption was not enabled for this task */
#if PROBLEM1

void vLedToggle( void * pvParameters )
{
   
    for( ;; )
    {        
				/* Write High on P0.0 */
				GPIO_write(PORT_0, PIN0, PIN_IS_HIGH);
			  
				/* Delay of 1000 tick, each tick = 1ms. Equivalent to total delay of 1 second */
				vTaskDelay(1000);
			  
			  /* Write Low on P0.0 */
				GPIO_write(PORT_0, PIN0, PIN_IS_LOW);
			
				vTaskDelay(1000);			
			
    }
}

#endif

/* Problem 2 Tasks */
/* preemption was not enabled for this task */
#if PROBLEM2

void vLedToggle100( void * pvParameters )
{
   
    for( ;; )
    {        
				/* Write High on P0.0 */
				GPIO_write(PORT_0, PIN0, PIN_IS_HIGH);
			  
				/* Delay of 100 tick, each tick = 1ms. Equivalent to total delay of 0.1 second */
				vTaskDelay(100);
			  
			  /* Write Low on P0.0 */
				GPIO_write(PORT_0, PIN0, PIN_IS_LOW);
			
				vTaskDelay(100);			
			
    }
}

void vLedToggle500( void * pvParameters )
{
   
    for( ;; )
    {        
				/* Write High on P0.1 */
				GPIO_write(PORT_0, PIN1, PIN_IS_HIGH);
			  
				/* Delay of 500 tick, each tick = 1ms. Equivalent to total delay of 0.5 second */
				vTaskDelay(500);
			  
			  /* Write Low on P0.1 */
				GPIO_write(PORT_0, PIN1, PIN_IS_LOW);
			
				vTaskDelay(500);			
			
    }
}

void vLedToggle1000( void * pvParameters )
{
   
    for( ;; )
    {        
				/* Write High on P0.2 */
				GPIO_write(PORT_0, PIN2, PIN_IS_HIGH);
			  
				/* Delay of 1000 tick, each tick = 1ms equivalent total delay of 1 second */
				vTaskDelay(1000);
			  
			  /* Write Low on P0.2 */
				GPIO_write(PORT_0, PIN2, PIN_IS_LOW);
			
				vTaskDelay(1000);			
			
    }
}

#endif

/* Problem 3 Tasks */
/* preemption was enabled for this task */
#if PROBLEM3


/*---- vButtonCheck Task Description --------------------------------
*
*   Task executes every 0.2s. Countet increase whenever button is
*   pressed. Continiously check for counter limits to raise the flag
*		of the appropriate task. Since the counter increments each 0.2s,
* 	10 = 2s & 20 = 4s
*
*-------------------------------------------------------------------*/
void vButtonCheck( void * pvParameters )
{
	pinState_t CurrentState;
	pinState_t PrevState;
	
	for( ;; )
    {   
				PrevState = GPIO_read(PORT_0, PIN3);
			
  			if(PIN_IS_HIGH == PrevState)
				{
					/* Counter increase every 0.2 seconds */
					counter++;
					
					
					/* Button released */
					if(CurrentState == PIN_IS_LOW)
					{
						/* restart counter to start another check */
						counter  = 1;
						
					}
									
				}		
				
				/* less than 2 second passed */
				if(counter < 10)
				{
					Task1 = 1;
					Task2 = 0;
					Task3 = 0;
				}
				
				/* More than or equal 2 seconds and less than or equal 4 seconds passed */
				else if(counter >= 10 && counter <= 20)
				{
					Task2 = 1;
					Task1 = 0;
					Task3 = 0;
				}
				
				/* More than 4 seconds passed */
				else if( counter > 20 )
				{
					Task3 = 1;
					Task2 = 0;
					Task1 = 0;
				}
				
				CurrentState	= GPIO_read(PORT_0, PIN3);
				
				/* Delay of 200 tick, each tick = 1ms. Equivalent to total delay of 0.2 second */
					vTaskDelay(200);
				
			}
}

/*---- vLedOffZeroPlusSec Task Description -------------------------
*
*   Task executes if the button was pressed for less than 2s.
*   Task turns off the led on P0.4
*
*-------------------------------------------------------------------*/
void vLedOffZeroPlusSec( void * pvParameters )
{
	pinState_t ButtonState;
	
	for( ;; )
    { 
			ButtonState = GPIO_read(PORT_0, PIN3);
			
			/* Only execute this behaviour if the button was pressed for
				 less than 2 seconds */
			if(Task1 == 1 && Task2 == 0 && Task3 == 0 && ButtonState == PIN_IS_LOW)
			{
				GPIO_write(PORT_0, PIN4, PIN_IS_LOW);
				
  		}
				
		}
}

/*---- vLedToggleTwoPlusSec Task Description -----------------------
*
*   Task executes if the button was pressed for more than or equal
*		to 2s and less than or equal to 4s.
*   Task toggles the led on P0.4 with preodicity of 0.4s
*
*-------------------------------------------------------------------*/
void vLedToggleTwoPlusSec( void * pvParameters )			
{
	  pinState_t ButtonState;
	
		for( ;; )
		{ 
			ButtonState = GPIO_read(PORT_0, PIN3);
			
			/* Only execute this behaviour if the button was pressed for
				 less than or equal to 4 seconds and more than or equal to
				 2 seconds and is released for now */
			if(Task1 == 0 && Task2 == 1 && Task3 == 0 && ButtonState == PIN_IS_LOW)
			{	
					GPIO_write(PORT_0, PIN4, PIN_IS_HIGH);
					
					vTaskDelay(400);
					
					GPIO_write(PORT_0, PIN4, PIN_IS_LOW);
					
					vTaskDelay(400);			
			}
		}		
}

/*---- vLedToggleFourPlusSec Task Description -----------------------
*
*   Task executes it's body if the button was pressed for more than 4s
*   Task toggles the led on P0.4 with preodicity of 0.1s
*
*-------------------------------------------------------------------*/
void vLedToggleFourPlusSec( void * pvParameters )			
{		
	  pinState_t ButtonState;
	
		for( ;; )
    { 
			ButtonState = GPIO_read(PORT_0, PIN3);
			
			/* Only execute this behaviour if the button was pressed for
				 more than 4 seconds and is released for now */
			if(Task1 == 0 && Task2 == 0 && Task3 == 1 && ButtonState == PIN_IS_LOW)
			{
					GPIO_write(PORT_0, PIN4, PIN_IS_HIGH);
					
					vTaskDelay(100);
					
					GPIO_write(PORT_0, PIN4, PIN_IS_LOW);
					
					vTaskDelay(100);			
			}			
  	}				
}

#endif




