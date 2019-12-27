#include "pwm1.h"

void app_main()
{    
    pwm_config();
    
    while (1) {
        pwm_main(4000);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        pwm_main(2000);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        pwm_main(0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
