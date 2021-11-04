#include "stm32f0xx_gpio.h"
#include "debug.h"

#define DEBUG_GPIO_PORT               	GPIOB
#define ASU_A4_PIN_SystemTick         	GPIO_Pin_0
#define ASU_A5_PIN_TaskCounter        	GPIO_Pin_1
#define ASU_D9_PIN_TaskKey        		GPIO_Pin_3
#define ASU_D10_PIN_TaskLed        		GPIO_Pin_12
#define ASU_D13_PIN_TaskWatch      		GPIO_Pin_13
#define ASU_D12_PIN_TaskPoti       		GPIO_Pin_14
#define ASU_D11_PIN_TaskMandelbrot    	GPIO_Pin_15

void Debug_Init(void)
{
	/* Enable clock for LED gpio port registers */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);

	/* LEDs are low active! */
	/* -> a '0' on the gpio pin turns the LED on */
	/* Thatswhy set all gpio pins to '1' before init */
	DEBUG_GPIO_PORT->BSRR |= ASU_A4_PIN_SystemTick | ASU_A5_PIN_TaskCounter |
							 ASU_D9_PIN_TaskKey | ASU_D10_PIN_TaskLed |
							 ASU_D13_PIN_TaskWatch | ASU_D11_PIN_TaskMandelbrot|
	                         ASU_D12_PIN_TaskPoti;
  
	/* Init all LEDs */
	GPIO_InitTypeDef gpioInit;
	GPIO_StructInit(&gpioInit);
  
	gpioInit.GPIO_Mode = GPIO_Mode_OUT;
	gpioInit.GPIO_OType = GPIO_OType_PP;
	gpioInit.GPIO_Pin = ASU_A4_PIN_SystemTick | ASU_A5_PIN_TaskCounter |
						ASU_D9_PIN_TaskKey | ASU_D10_PIN_TaskLed |
						ASU_D13_PIN_TaskWatch | ASU_D11_PIN_TaskMandelbrot|
	                    ASU_D12_PIN_TaskPoti;
						
	DEBUG_GPIO_PORT->ODR = 0x00000000;
	GPIO_Init(DEBUG_GPIO_PORT, &gpioInit);
}



void Set_Tick_Debug(void)
{
	GPIO_SetBits(DEBUG_GPIO_PORT,ASU_A4_PIN_SystemTick);
}

void Reset_Tick_Debug(void)
{
	GPIO_ResetBits(DEBUG_GPIO_PORT,ASU_A4_PIN_SystemTick);
}


void Set_TaskCounter_Debug(void)
{
	GPIO_SetBits(DEBUG_GPIO_PORT,ASU_A5_PIN_TaskCounter);
}

void Reset_TaskCounter_Debug(void)
{
	GPIO_ResetBits(DEBUG_GPIO_PORT,ASU_A5_PIN_TaskCounter);
}




void Set_TaskKey_Debug(void)
{
	GPIO_SetBits(DEBUG_GPIO_PORT,ASU_D9_PIN_TaskKey);
}

void Reset_TaskKey_Debug(void)
{
	GPIO_ResetBits(DEBUG_GPIO_PORT,ASU_D9_PIN_TaskKey);
}




void Set_TaskLed_Debug(void)
{
	GPIO_SetBits(DEBUG_GPIO_PORT,ASU_D10_PIN_TaskLed);
}

void Reset_TaskLed_Debug(void)
{
	GPIO_ResetBits(DEBUG_GPIO_PORT,ASU_D10_PIN_TaskLed);
}



void Set_TaskWatch_Debug(void)
{
	GPIO_SetBits(DEBUG_GPIO_PORT,ASU_D13_PIN_TaskWatch);
}

void Reset_TaskWatch_Debug(void)
{
	GPIO_ResetBits(DEBUG_GPIO_PORT,ASU_D13_PIN_TaskWatch);
}



void Set_TaskPoti_Debug(void)
{
	GPIO_SetBits(DEBUG_GPIO_PORT,ASU_D12_PIN_TaskPoti);
}

void Reset_TaskPoti_Debug(void)
{
	GPIO_ResetBits(GPIOB,ASU_D12_PIN_TaskPoti);
}



void Set_TaskMandelbrot_Debug(void)
{
	GPIO_SetBits(DEBUG_GPIO_PORT,ASU_D11_PIN_TaskMandelbrot);
}

void Reset_TaskMandelbrot_Debug(void)
{
	GPIO_ResetBits(DEBUG_GPIO_PORT,ASU_D11_PIN_TaskMandelbrot);
}




