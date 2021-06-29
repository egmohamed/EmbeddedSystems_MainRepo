/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Peripheral includes. */
#include "GPIO.h"

/* Module includes */
#include "InterProcessCommTasks.h"

#if PROBLEM3

/* Module Global Declarations */
extern struct AMessage xMessage100;

#endif

/* Problem 1 Tasks */
/* preemption was not enabled for this task */
#if PROBLEM1

void vButtonCheck( void * pvParameters )
{
    unsigned char CurrentState = PIN_IS_LOW;
	unsigned char PrevState    = PIN_IS_LOW;
	
    for( ;; )
    {    
			/* Get the current state of button */
			CurrentState =  GPIO_read(PORT_0, PIN1);
			
			/* Indication of state change */
			if(CurrentState != PrevState)
			{				
						/* LEt action of toggling led take place only when the button is released */
			    	if(CurrentState == PIN_IS_LOW && PrevState == PIN_IS_HIGH)
						{
							xSemaphoreGive(xSemaphore);
							
						}
						
						/* Keep track of button state */
						PrevState = CurrentState;
			}
			
			/* a small delay to switch fast between the two tasks */
			vTaskDelay(1);
		}	
}

void vLedToggle( void * pvParameters )
{ 
    for( ;; )
    {   
				/* Attempt to take the semaphore */
				if(xSemaphoreTake( xSemaphore, ( TickType_t ) portMAX_DELAY ))
				{		
						/* Toggle the led on P0.0 if the semaphore acquired successfully */
						GPIO_Toggle(PORT_0, PIN0);						
				}
				
				/* a small delay to switch fast between the two tasks */
				vTaskDelay(1);
    }
}

#endif

/* Problem 2 Tasks */
/* preemption was not enabled for this task */
#if PROBLEM2

void vWriteStr100( void * pvParameters )
{  
	const signed char Str1[] = "|1st Str with 100ms ";
	unsigned char counter1 			  = 0;
	signed portBASE_TYPE Str1Ret  = 0;
	const signed char * pcString1 = NULL;
	
    for( ;; )
    {   
				/* Assign reference to char array to the pointer */
				pcString1 = Str1;
				
				/* Put char by char on txBuffer to send */
				/* The whole string is printed when Str1Ret == pdTRUE */
				Str1Ret = vSerialPutString(pcString1, 20);
			
				if(Str1Ret == pdTRUE)
				{
					counter1++;
					
				}
				
				/* 10 Strings sent through UART */
				if(counter1 == 10)
				{
					counter1 = 0;
					
					/* Delay task only when sending 10 strings
					to start executing the other task */
					vTaskDelay(100);
				}		
    }
}

void vWriteStr500( void * pvParameters )
{
	unsigned char counter2 = 0;
	signed portBASE_TYPE Str2Ret = 0;
	volatile char DummyVar = 0;
	unsigned long i;
	const signed char * pcString2 = NULL;
	const signed char Str2[] = "|2nd Str with 500ms ";
	pcString2 = Str2;
	
    for( ;; )
    {        
			  /* Put char by char on txBuffer to send */
			  /* The whole string is printed when Str1Ret == pdTRUE */
		    Str2Ret = vSerialPutString(pcString2, 20);
			
			  if(Str2Ret == pdTRUE)
			  {
					counter2++;
					
					/* Simulate heavy load after each string sending */
					for(i = 0; i< 100000; i++)
					{
						/* Dummy instruction */
						DummyVar++;
					}
				}
				
				/* 10 Strings sent through UART */
				if(counter2 == 10)
				{
					counter2 = 0;
					
					/* Delay task only when sending 10 strings
					to start executing the other task */
					vTaskDelay(500);
				}	
    }
}

#endif

/* Problem 3 Tasks */
/* preemption was not enabled for this task */
#if PROBLEM3

void vButtonCheck1( void * pvParameters )
{
	pinState_t CurrentState1 = PIN_IS_LOW;
	pinState_t PrevState1 	 = PIN_IS_HIGH;

	for( ;; )
    {   
				/* Get the current state of button */
				CurrentState1 = GPIO_read(PORT_0, PIN1);
			
				/* Indication of state change */
  			if(CurrentState1 != PrevState1)
				{
						/* In case of state change send notification to consumer task
							 with the value of the changed state. TASK1 used to indicate the sender
							 which is vButtonCheck1 in this case */
					  xTaskNotify( ConsumerTask_Handler, CurrentState1 + TASK1, eSetValueWithOverwrite);
				   
					  
					  PrevState1 = CurrentState1;
									
				}		
				
				/* Delay of 50 tick, each tick = 1ms. Equivalent to total delay of 50ms */
					vTaskDelay(50);
				
			}
}

void vButtonCheck2( void * pvParameters )
{
	pinState_t CurrentState2 = PIN_IS_LOW;
	pinState_t PrevState2    = PIN_IS_HIGH;
	
	  for( ;; )
    { 
				CurrentState2 = GPIO_read(PORT_0, PIN2);
				
  			if(CurrentState2 != PrevState2)
				{
					 /* In case of state change send notification to consumer task
							 with the value of the changed state. TASK2 used to indicate the sender
							 which is vButtonCheck2 in this case */
					 xTaskNotify( ConsumerTask_Handler, CurrentState2 + TASK2, eSetValueWithOverwrite);
				  
				 	 PrevState2 = CurrentState2;
									
				}		
				
					vTaskDelay(50);
				
			}				
}

void vSendString100( void * pvParameters )			
{	
		for( ;; )
		{ 
				if( xQueue != 0 )
				{
						/* Send a pointer to a struct AMessage object. Don't block if the
						queue is already full. xMessage100 is copied to queue */
						xQueueSend( xQueue, (void *)&xMessage100, 0 );
				}
				
				vTaskDelay(100);
		}		
}

void vConsumerTask( void * pvParameters )			
{		
	  unsigned int ulNotifiedValue;
		const signed char* Pstr = NULL;
	
		const signed char HighStr1[] = "Button triggered to HIGH1 ";
		const signed char LowStr1 [] = "Button triggered to LOW1 " ;
	  const signed char HighStr2[] = "Button triggered to HIGH2 ";
		const signed char LowStr2 [] = "Button triggered to LOW2 " ;
	  
	  struct AMessage MessageRx;
	
		for( ;; )
    { 				
			
			xTaskNotifyWait(   0x00,     		    	 /* Don't clear any notification bits on entry. */
                         0xFFFFFFFF, 			     	 /* Reset the notification value to 0 on exit.  */
                         &ulNotifiedValue, 	             /* Notified value pass out in ulNotifiedValue. */
                         0 							 );  /* Don't block. 																*/
				
				/* Bit 0 was set - process whichever event is represented by bit 0. */
			  if( ( ulNotifiedValue & 0x01 ) != 0 &&  ( ulNotifiedValue & 0x02 ) == 0 )
        {
						/* Assign pointer to appropriate string */
						Pstr = LowStr1;
            
						/* Send the string specified with pointer Pstr */
            vSerialPutString(Pstr, 25);
        }
				
				/* Bit 1 was set - process whichever event is represented by bit 1. */
				else if( ( ulNotifiedValue & 0x02 ) != 0 && ( ulNotifiedValue & 0x01 ) == 0)
				{
						Pstr = HighStr1;			
						vSerialPutString(Pstr, 26);
				}
				
				/* Bit 0 & 1 were set - process whichever event is represented by bit 0 & 1. */
				else if( ( ulNotifiedValue & 0x02 ) != 0  && ( ulNotifiedValue & 0x01 ) != 0 )
				{
						Pstr = LowStr2;					
						vSerialPutString(Pstr, 25);
				}
				
				/* Bit 2 was set - process whichever event is represented by bit 2. */
				else if( ( ulNotifiedValue & 0x04 ) != 0 )
				{
						Pstr = HighStr2;
						vSerialPutString(Pstr, 26);
				}
				
				/* Receive the sent queue without blocking in case of empty queue */
				/* Message saved in MessageRx with the same size of bytes as in queue creation */
				xQueueReceive( xQueue, &MessageRx, 0 );
				
				/* Send the received string through the UART */
			    vSerialPutString(MessageRx.ucData, 16);
				
				/* Checking for received values and Sending operation occurs every 100ms */
				vTaskDelay(100);
		}
}

#endif




