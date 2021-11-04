/**
 ******************************************************************************
 * @file    Debug.h
 
 ******************************************************************************
 */

/** \
 */

#ifndef DEBUG_H
#define DEBUG_H


#include "Services/StdDef.h"


#define TaskCounter_DEBUG 1
#define TaskKey_DEBUG 1
#define LED_DEBUG 1
#define Systick_DEBUG 1


void Debug_Init(void);
void Set_Tick_Debug(void);
void Reset_Tick_Debug(void);

void Set_TaskCounter_Debug(void);
void Reset_TaskCounter_Debug(void);

void Set_TaskKey_Debug(void);
void Reset_TaskKey_Debug(void);

void Set_TaskLed_Debug(void);
void Reset_TaskLed_Debug(void);

void Set_TaskWatch_Debug(void);
void Reset_TaskWatch_Debug(void);


void Set_TaskPoti_Debug(void);
void Reset_TaskPoti_Debug(void);

void Set_TaskMandelbrot_Debug(void);
void Reset_TaskMandelbrot_Debug(void);


void Set_Counter_Debug(void);
void Reset_Counter_Debug(void);


#endif
