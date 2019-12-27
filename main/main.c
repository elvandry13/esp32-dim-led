#include "adc1.h"
#include "pwm1.h"

void app_main()
{
    adc_config();
    pwm_config();
    while(1)
    {
        int pot_in = adc_main();
        printf("Potensio input value = %d\n", pot_in);
        // TO DO -> add map function here
        int pwm_out;
        printf("PWM output value = %d\n", pwm_out);
        pwm_main(pwm_out);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
