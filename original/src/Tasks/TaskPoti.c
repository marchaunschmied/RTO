#include "BSP/TftDisplay.h"
#include "StdDef.h"
#include "TaskPoti.h"
#include "BSP/debug.h"

void TaskPoti (void)
{
	Set_TaskPoti_Debug();
	Tft_DrawString(10, 18+4*24, "Poti ");
	Reset_TaskPoti_Debug();	
}
