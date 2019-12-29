#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


int map(int input, int adc_min, int adc_max, int pwm_min, int pwm_max);
