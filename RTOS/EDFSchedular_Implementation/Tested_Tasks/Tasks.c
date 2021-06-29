#include "Tasks.h"
#include "FreeRTOS.h"
#include "task.h"
#include "GPIO.h"

/* Tasks Handlers */
TaskHandle_t Task1Handler = NULL;
TaskHandle_t Task2Handler = NULL;

/* Deadline detector definitions */
unsigned long timeStamp = 0;
unsigned long TasksCounter = 0;			
unsigned long TasksNo = 0;
unsigned long TasksDeadline[configMAX_PRIORITIES];
unsigned long DelayedtimeStamps [configMAX_PRIORITIES];
unsigned long SwitchIntimeStamps[configMAX_PRIORITIES];
unsigned long MissedDeadline = 0;
unsigned long DiffTime = 0;
void * volatile PrevSwitchIn = NULL;
void * volatile CurrSwitchIn = NULL;

/*EDF algorithm definitions */
EDF_t EDF_Instance;
unsigned char i;
unsigned char PeriodAssignedFlag = 0;
void*  HandlersArr[configMAX_PRIORITIES];
unsigned char i1;
unsigned char TasksNoCp = 0;
unsigned char TasksNo2;
unsigned long tickCounterTimer = 0;
unsigned char Priority1Check = 0;
unsigned char Priority2Check = 0;

/* Utility functions */
int cmpfunc (const void * a, const void * b) 
{
   return ( *(unsigned long*)a - *(unsigned long*)b );
}

void EDF_CountInit(void)
{
	unsigned char i;
	for(i = 0; i< configMAX_PRIORITIES; i++)
	{
		EDF_Instance.EDF_Counter[i] = 1;
	}
}

/* Part of EDF algorithm */
void SortAndSetPriority(void)
{
	unsigned char count = 0, count1 = 0;
	unsigned long TempArr[configMAX_PRIORITIES] = {0};

	TasksNoCp = TasksNo;
	for(count = 0; count < TasksNoCp - 1; count++)
	{
		TempArr[count] =  EDF_Instance.ArrDistFromDeadlines[count];
	}
	qsort(TempArr, configMAX_PRIORITIES, sizeof(unsigned long), cmpfunc);
	
	for(count = 0; count < configMAX_PRIORITIES; count++)
	{
		if(TempArr[count] > 0)
		{
			--TasksNoCp;
		}
		for(count1 = 0; count1 < configMAX_PRIORITIES; count1++)
		{
			if(TempArr[count] == EDF_Instance.ArrDistFromDeadlines[count1])
			{	
				if(TasksNoCp >= 0 && EDF_Instance.ArrDistFromDeadlines[count1] > 0)
				{
					
					vTaskPrioritySet((TaskHandle_t )HandlersArr[count1], TasksNoCp);
					Priority2Check =  uxTaskPriorityGet( Task2Handler );
					Priority1Check = uxTaskPriorityGet( Task1Handler );
					
				}
			}
		}
	}
	
}

/* Tasks definitions */
void Task1(void * pvParameters)
{
	TickType_t xLastWakeTime;
	int i; volatile int x = 0;
	xLastWakeTime = xTaskGetTickCount();
	
	for(;;)
	{
		GPIO_write(PORT_0, PIN1, PIN_IS_HIGH);
		for(i = 0; i< 35000; i++)
		{
			x = 1;
		}
		GPIO_write(PORT_0, PIN1, PIN_IS_LOW);
		vTaskDelayUntil(&xLastWakeTime, 10);
	
	}	
}

void Task2(void * pvParameters)
{
	TickType_t xLastWakeTime;
	int x = 0; int i;
	xLastWakeTime = xTaskGetTickCount();
	
	for(;;)
	{
		GPIO_write(PORT_0, PIN0, PIN_IS_HIGH);
		for(i = 0; i< 35000; i++)
		{
			x = 2;
		}
		GPIO_write(PORT_0, PIN0, PIN_IS_LOW);
		vTaskDelayUntil(&xLastWakeTime, 40);
	
	}
}
