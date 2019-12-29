# esp32-dim-led
Led dimmer using ESP32 board and ESP-IDF (IoT Development Framework)

The aim of this project is to control the LED's brightness via potentiometer. I use ADC (Analog to Digital) pin to convert potentiometer value (analog) into digital value. For controlling the LED's brightness, I use PWM (Pulse Width Modulation) pin that will varying the voltage output. The PWM output value depends on ADC input value using map function, so the range of ADC value will match with the range of PWM value. For additional, I add LCD crystal to display the ADC and PWM value.

## Wiring
- Potentiometer --> ESP32 Board
    - VCC --> VCC (5V)
    - GND --> GND
    - Out --> GPIO 36

- LCD Display --> ESP32 Board
    - VCC --> VCC
    - GND --> GND
    - SCL --> GPIO 22
    - SDA --> GPIO 21

- LED built in --> GPIO 2

## Build and Flash
Before compile and flash the code to the ESP32, make sure you have configure the COM port in Make Menuconfig. Type this in your terminal :
> make menuconfig

After that, simply type this command to build and flash the code to ESP32. Make sure you are inside the project repository (where there is a Makefile) :
> make flash

To open the serial monitor in your terminal, type this command :
> make monitor