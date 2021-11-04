#ifndef APOS_H
#define APOS_H

#include "Services/StdDef.h"



#define TASK_STACK_SIZE 1024

typedef struct OS_TCB
{
  uint32_t *stack_address;
	
}APOS_TCB_STRUCT;




// Initialisert das Echtzeitbetriebssystem 
void APOS_Init(void); 

void APOS_TASK_Create(APOS_TCB_STRUCT* 	pTask, // TaskControlBlock 
						const char* 	pTaskName, // Task Name – nur für Debug-Zwecke 
						uint32_t 		Priority, // Priorität des Tasks (vorerst nicht in Verwendung) 
						void 			(*pRoutine)(void), // Startadresse Task (ROM) 
						void* 			pStack, // Startadresse Stack des Tasks (RAM) 
						uint32_t 		StackSize, // Größe des Stacks 
						uint32_t 		TimeSlice // Time-Slice für Round Robin Scheduling 
                      );
					  
					  
void APOS_Start(void); 





#endif
