#define USE_STDPERIPH_DRIVER
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

//Quick hack, approximately 1ms delay
void ms_delay(int ms) {
	while (ms-- > 0) {
		volatile int x = 5971;
		while (x-- > 0)
			__asm("nop");
	}
}

void delay(float time) {
	while (time-- > 0) {
		__asm("nop");
	}
}

int rotate_1(int step) {
	GPIO_Write(GPIOD, GPIO_Pin_1);
	delay(step);
	GPIO_Write(GPIOD, GPIO_Pin_3);
	delay(step);
	GPIO_Write(GPIOD, GPIO_Pin_5);
	delay(step);
	GPIO_Write(GPIOD, GPIO_Pin_7);
	delay(step);
	return 0;
}

int rotate_0(int step) {
	GPIO_Write(GPIOD, GPIO_Pin_7);
	delay(step);
	GPIO_Write(GPIOD, GPIO_Pin_5);
	delay(step);
	GPIO_Write(GPIOD, GPIO_Pin_3);
	delay(step);
	GPIO_Write(GPIOD, GPIO_Pin_1);
	delay(step);
	return 0;
}
int rotate_led(int step) {

	GPIO_SetBits(GPIOD, GPIO_Pin_12); // turn on green
	ms_delay(step);
	GPIO_ResetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13);

	GPIO_SetBits(GPIOD, GPIO_Pin_13); // turn on green
	ms_delay(step);
	GPIO_ResetBits(GPIOD, GPIO_Pin_13);

	GPIO_SetBits(GPIOD, GPIO_Pin_14); // turn on green
	ms_delay(step);
	GPIO_ResetBits(GPIOD, GPIO_Pin_14);

	GPIO_SetBits(GPIOD, GPIO_Pin_15); // turn on green
	ms_delay(step);
	GPIO_ResetBits(GPIOD, GPIO_Pin_15);

//	GPIO_ResetBits(GPIOD,
//			GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
//	ms_delay(step);

	return 0;
}

int rotate_led2(int step) {
	GPIO_Write(GPIOD, GPIO_Pin_12); // turn on green
	ms_delay(step);
	GPIO_Write(GPIOD, GPIO_Pin_12 | GPIO_Pin_13); // turn on green
	ms_delay(step);

	GPIO_Write(GPIOD, GPIO_Pin_13); // turn on green
	ms_delay(step);

	GPIO_Write(GPIOD, GPIO_Pin_13 | GPIO_Pin_14); // turn on green
	ms_delay(step);

	GPIO_Write(GPIOD, GPIO_Pin_14); // turn on green
	ms_delay(step);
	GPIO_Write(GPIOD, GPIO_Pin_14 | GPIO_Pin_15); // turn on green
	ms_delay(step);

	GPIO_Write(GPIOD, GPIO_Pin_15); // turn on green
	ms_delay(step);
	GPIO_Write(GPIOD, GPIO_Pin_15 | GPIO_Pin_12); // turn on green
	ms_delay(step);

//	GPIO_ResetBits(GPIOD,
//			GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
//	ms_delay(step);

	return 0;
}

void round_rotate(int dir, int step) {
	int one_round = 162;
	while (one_round-- > 0) {
		if (dir == 1) {
			rotate_1(step);
		} else {
			rotate_0(step);
		}
	}
}

void time_rotate(int ms, int dir, int step) {
	while (ms-- > 0) {
		round_rotate(dir, step);
	}
}

GPIO_InitTypeDef GPIO_InitStructure;

//Flash orange LED at about 1hz
int main(void) {
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); // start clock on GPIOD

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_3 | GPIO_Pin_5
			| GPIO_Pin_7 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	// enable FPU ;D
	SCB->CPACR |= ((3ul << 10 * 2) | (3ul << 11 * 2));

	rotate_1(5 * 5971);
	rotate_1(5 * 5971);
	rotate_1(5 * 5971);
	rotate_1(5 * 5971);
	rotate_1(5 * 5971);
//	rotate_0(1);

	return 0;

}
