#include "map.h"

//this function is formula for mapping ADC value (input) to PWM value (output)
int map(int input, int adc_min, int adc_max, int pwm_min, int pwm_max)
{
  int output;
  return output = (input - adc_min) * (pwm_max - pwm_min) / (adc_max - adc_min) + pwm_min;
}
