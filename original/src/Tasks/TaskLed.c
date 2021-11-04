#include "BSP/TftDisplay.h"
#include "StdDef.h"
#include "TaskLed.h"
#include "BSP/debug.h"

void TaskLed (void)
{
	Set_TaskLed_Debug();
	Tft_DrawString(10, 18+2*24, "Led ");
	Reset_TaskLed_Debug();	
}
