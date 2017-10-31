#include "SysTick.h"

volatile uint32_t sysTickUptime = 0;
// Return system uptime in microseconds (rollover in 70minutes)
//返回 us
uint32_t micros(void)
{
  register uint32_t ms, cycle_cnt;
  do 
  {
    ms = sysTickUptime;
    cycle_cnt = SysTick->VAL;
  } while (ms != sysTickUptime);
  return (ms * 1000) + 1000 - (unsigned int)(cycle_cnt / 12.5 + 0.5);
}

// Return system uptime in milliseconds (rollover in 49 days)
uint32_t millis(void)
{
  return sysTickUptime;
}

void SysTick_Init(void)
{
  SysTick->LOAD = 12500;   //SystemCoreClock/2   12.5Mhz
  SysTick->VAL = 0x00;
  SysTick->CTRL = SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_TICKINT_Msk; 
}

void delay_ms(uint16_t nms)
{
  uint32_t t0 = micros();
  while(micros() - t0 < nms * 1000);
}

void get_time(unsigned long *time)
{
  *time = millis();
}

void SysTick_Handler(void)
{
  sysTickUptime++;
}
