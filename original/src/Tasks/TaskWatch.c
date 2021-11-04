#include "BSP/TftDisplay.h"
#include "StdDef.h"
#include "TaskWatch.h"
#include "BSP/debug.h"

void TaskWatch (void)
{
	Set_TaskWatch_Debug();
	Tft_DrawString(10, 18+3*24, "Watch ");
	Reset_TaskWatch_Debug();
}
