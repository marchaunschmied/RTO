#include "BSP/TftDisplay.h"
#include "StdDef.h"
#include "TaskKey.h"
#include "BSP/debug.h"

void TaskKey (void)
{
	Set_TaskKey_Debug();
	Tft_DrawString(10, 18+1*24, "Key ");
	Reset_TaskKey_Debug();	
}
