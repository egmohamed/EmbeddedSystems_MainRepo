#ifndef __TASKS_H__
#define __TASKS_H__

#undef configMAX_PRIORITIES

#define configMAX_PRIORITIES ( 4 )
#define TimerToTickResolution  60

/* Tasks declarations */
void Task1(void * pvParameters);
void Task2(void * pvParameters);

/* Utility functions declarations */
void SortAndSetPriority(void);
void EDF_CountInit(void);
int cmpfunc (const void * a, const void * b);

/* Deadline detector declarations */
extern unsigned long timeStamp;
extern unsigned long TasksCounter;
extern unsigned long TasksNo;
extern unsigned long TasksDeadline[];
extern unsigned long DelayedtimeStamps[];
extern unsigned long SwitchIntimeStamps[];
extern unsigned long MissedDeadline;
extern unsigned long DiffTime;
extern unsigned char PeriodAssignedFlag;
extern void * volatile PrevSwitchIn;
extern void * volatile CurrSwitchIn;

/* EDF algorithm declarations */
typedef struct
{
	unsigned long long EDF_Counter[configMAX_PRIORITIES];
	unsigned long long EDF_TasksDeadlines[configMAX_PRIORITIES];
	unsigned long long DistanceFromDeadline;
  unsigned long ArrDistFromDeadlines[configMAX_PRIORITIES];
	unsigned long tickCounter;
	
	
}EDF_t;

extern EDF_t EDF_Instance;
extern unsigned char i;
extern void*  HandlersArr[configMAX_PRIORITIES];
extern unsigned char i1;
extern unsigned char TasksNoCp;
extern unsigned char TasksNo2;
extern unsigned long tickCounterTimer;
extern unsigned char Priority1Check;
extern unsigned char Priority2Check;
#endif
