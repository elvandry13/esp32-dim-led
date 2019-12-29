#ifndef __HD44780_H
#define __HD44780_H

#include <stdio.h>
#include <stdint.h>
#include <esp_log.h>
#include <driver/i2c.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "sdkconfig.h"
// #include "esp32/rom/ets_sys.h"


#ifdef __cplusplus
 extern "C" {
#endif

#pragma once

// static esp_err_t I2C_init(void);

void LCD_init(uint8_t addr, uint8_t dataPin, uint8_t clockPin, uint8_t cols, uint8_t rows);

void LCD_setCursor(uint8_t col, uint8_t row);

void LCD_writeChar(char c);

void LCD_writeStr(char* str);

void LCD_home(void);

void LCD_clearScreen(void);

// static void LCD_writeNibble(uint8_t nibble, uint8_t mode);

// static void LCD_writeByte(uint8_t data, uint8_t mode);

// static void LCD_pulseEnable(uint8_t data);


#ifdef __cplusplus
}
#endif

#endif
