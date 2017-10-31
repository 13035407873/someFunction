#ifndef __SYSTICK_H
#define __SYSTICK_H

#include "gvm32f030.h"

void SysTick_Init(void);
uint32_t micros(void);
uint32_t millis(void);
void delay_ms(uint16_t nms);
void get_time(unsigned long *time);

extern volatile uint32_t sysTickUptime;

#endif


