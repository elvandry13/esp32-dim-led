#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"

static void check_efuse();

static void print_char_val_type(esp_adc_cal_value_t val_type);

void adc_config();

uint32_t adc_main();
