#include "BSP/TftDisplay.h"
#include "StdDef.h"
#include "TaskCounter.h"
#include <stdio.h>
#include "BSP/debug.h"

#define MAX_LEN 14		// Maximale Anzahl Zeichen pro Zeile
static char tmpBuf[MAX_LEN];

void TaskCounter (void)
{
	Set_TaskCounter_Debug();
	static uint32_t counter = 0;
	
	counter++;
	snprintf(tmpBuf, MAX_LEN, "%d", counter);
	Tft_DrawString(10, 18+0*24, "Cnt ");	
	Tft_DrawString(10 + 16*7, 18+0*24, tmpBuf);	
	Reset_TaskCounter_Debug();
}
