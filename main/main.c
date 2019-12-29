#include "adc1.h"
#include "pwm1.h"
#include "map.h"
#include "lcd1.h"

/*Define LCD configuration*/
#define LCD_ADDR 0x27
#define SDA_PIN  21
#define SCL_PIN  22
#define LCD_COLS 20
#define LCD_ROWS 4


void app_main()
{
    /*ADC configuration*/
    adc_config();
    
    /*PWM configuration*/
    pwm_config();
    
    /*LCD configuration*/
    LCD_init(LCD_ADDR, SDA_PIN, SCL_PIN, LCD_COLS, LCD_ROWS);
    LCD_home();
    LCD_clearScreen();

    while(1)
    {
        /*Get ADC value from Potensiometer as input*/
        int pot_in = adc_main();
        printf("Potensio input value = %d\n", pot_in);

        /*Mapping ADC range value to PWM range value,
        then store to PWM value as output*/
        int pwm_out = map(pot_in,0,4095,0,4000);
        printf("PWM output value = %d\n", pwm_out);
        pwm_main(pwm_out);

        /*Display ADC and PWM value to LCD*/
        char str_adc[20];
        char str_pwm[20];

        LCD_clearScreen();
        sprintf(str_adc, "ADC = %d", pot_in);
        LCD_setCursor(0, 0);
        LCD_writeStr(str_adc);

        sprintf(str_pwm, "PWM = %d", pwm_out);
        LCD_setCursor(0, 2);
        LCD_writeStr(str_pwm);

        /*Delay 1 second*/
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
