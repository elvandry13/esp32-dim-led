#include "adc1.h"
#include "pwm1.h"
#include "map.h"

void app_main()
{
    /*ADC configuration*/
    adc_config();
    
    /*PWM configuration*/
    pwm_config();
    
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

        /*Delay 1 second*/
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
