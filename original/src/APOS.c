#include "Services/StdDef.h"
#include "APOS.h"
//#include <core_cmFunc.h>

//setup stack space 
static uint32_t Task1_Stack[TASK_STACK_SIZE];
static uint32_t Task2_Stack[TASK_STACK_SIZE];
static uint32_t Task3_Stack[TASK_STACK_SIZE];

//static uint32_t Stacks[MAX_TASK_NUM][TASK_STACK_SIZE]; //

uint16_t task_index = 0;

// different Task Stack property
static APOS_TCB_STRUCT TCB_Group[MAX_TASK_NUM];

APOS_TCB_STRUCT *current_TCB;

extern void OSStart(void);

void test() {
 
}

void APOS_Init(void)
{
	current_TCB = &TCB_Group[task_index];
	APOS_TASK_Create(current_TCB, "noname",0, test,&Task1_Stack[TASK_STACK_SIZE],TASK_STACK_SIZE,0);
	
    
    OSStart();
	
}


/*
*
* pTask          	TaskControlBlock 
* pTaskName,     	Task Name ¨C nur f¨¹r Debug-Zwecke 
* Priority,        	Prioritoet des Tasks (vorerst nicht in Verwendung) 
* (*pRoutine)() 	Startadresse Task (ROM?????  Fuction name?
* pStack, 		    Startadresse Stack des Tasks (RAM) 
* StackSize, 	    Groesse des Stacks 
* TimeSlice 		Time-Slice f¨¹r Round Robin Scheduling 
*
*/
void APOS_TASK_Create(APOS_TCB_STRUCT* 	pTask, 					// TaskControlBlock 
						const char*    	pTaskName,      		// Task Name ¨C nur f¨¹r Debug-Zwecke 
						uint32_t       	Priority,        		// Prioritoet des Tasks (vorerst nicht in Verwendung) 
						void 			(*pRoutine)(void),     	// Startadresse Task (ROM?????
						void* 			pStack, 				// Startadresse Stack des Tasks (RAM) 
						uint32_t 		StackSize, 				// Groesse des Stacks 
						uint32_t 		TimeSlice 				// Time-Slice f¨¹r Round Robin Scheduling 
						)
{
	//pTask = &TCB_Group[task_index]; 
	//pTask->stack_addr = Stacks[task_index];
	
	uint32_t *stack_top = pStack; 
	
	
	//automatically saved
	*(--stack_top) = (uint32_t)pRoutine; 		// R15 PC function entry point
    *(--stack_top) = (uint32_t)0x14141414u; 	// R14 LR
    *(--stack_top) = (uint32_t)0x12121212u; 	// R12
    *(--stack_top) = (uint32_t)0x03030303u; 	// R3
    *(--stack_top) = (uint32_t)0x02020202u; 	// R2
    *(--stack_top) = (uint32_t)0x01010101u; 	// R1
    *(--stack_top) = (uint32_t)0x00000000u; 	// R0
	
	//manuel
	*(--stack_top) = (uint32_t)0x11111111u; // R11
    *(--stack_top) = (uint32_t)0x10101010u; // R10
    *(--stack_top) = (uint32_t)0x09090909u; // R9
    *(--stack_top) = (uint32_t)0x08080808u; // R8
    *(--stack_top) = (uint32_t)0x07070707u; // R7
    *(--stack_top) = (uint32_t)0x06060606u; // R6
    *(--stack_top) = (uint32_t)0x05050505u; // R5
    *(--stack_top) = (uint32_t)0x04040404u; // R4
	
	pTask->stack_addr = stack_top;
}

void PendSV_init(void) 
{
    NVIC_SetPriority(PendSV_IRQn, 0xFF);
}

void APOS_Start(void)
{
	PendSVInit();
    //

	
}

void APOS_Scheduler(void)
{
	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;// Bit 28 Set 1 to PendSV
}
