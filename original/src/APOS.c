#include "Services/StdDef.h"
#include "APOS.h"


static uint32_t Task1_Stack[TASK_STACK_SIZE];
static APOS_TCB_STRUCT TCB1;

void APOS_Init(void)
{
	//APOS_TASK_Create(TCB1, TaskA, 0, 0, &Task1_Stack[TASK_STACK_SIZE],TASK_STACK_SIZE,0);
	
}

void APOS_TASK_Create(APOS_TCB_STRUCT* pTask, 		// TaskControlBlock 
						const char*    pTaskName,      // Task Name ¨C nur f¨¹r Debug-Zwecke 
						uint32_t       Priority,          // Prioritoet des Tasks (vorerst nicht in Verwendung) 
						void (*pRoutine)(void),     // Startadresse Task (ROM) 
						void* pStack, 				// Startadresse Stack des Tasks (RAM) 
						uint32_t StackSize, 		// Groesse des Stacks 
						uint32_t TimeSlice 			// Time-Slice f¨¹r Round Robin Scheduling 
						)
{
	uint32_t *p;
	
}


void APOS_Start(void)
{
	//init PendSV
    //init SysTick;
}