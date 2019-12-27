#include "pwm1.h"

#define LEDC_HS_TIMER          LEDC_TIMER_0
#define LEDC_HS_MODE           LEDC_HIGH_SPEED_MODE
#define LEDC_HS_CH0_GPIO       (2)
#define LEDC_HS_CH0_CHANNEL    LEDC_CHANNEL_0

//PWM configuration
void pwm_config()
{
    // Set configuration of timer
    ledc_timer_config_t ledc_timer = {
        .duty_resolution = LEDC_TIMER_13_BIT, // resolution of PWM duty
        .freq_hz = 5000,                      // frequency of PWM signal
        .speed_mode = LEDC_HS_MODE,           // timer mode
        .timer_num = LEDC_HS_TIMER            // timer index
    };
    ledc_timer_config(&ledc_timer);

    // Set configuration of channel
    ledc_channel_config_t ledc_channel = {
        .channel    = LEDC_HS_CH0_CHANNEL,
        .duty       = 0,
        .gpio_num   = LEDC_HS_CH0_GPIO,
        .speed_mode = LEDC_HS_MODE,
        .hpoint     = 0,
        .timer_sel  = LEDC_HS_TIMER
    };
    ledc_channel_config(&ledc_channel);

}

//PWM output
void pwm_main(int duty_input)
{
    ledc_set_duty(LEDC_HS_MODE, LEDC_HS_CH0_CHANNEL, duty_input);
    ledc_update_duty(LEDC_HS_MODE, LEDC_HS_CH0_CHANNEL);
}

//Example of running PWM for controlling LED
void pwm_example()
{
    printf("1. LEDC set up to duty = 4000\n");
    ledc_set_duty(LEDC_HS_MODE, LEDC_HS_CH0_CHANNEL, 4000);
    ledc_update_duty(LEDC_HS_MODE, LEDC_HS_CH0_CHANNEL);
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    printf("2. LEDC set up to duty = 3000\n");
    ledc_set_duty(LEDC_HS_MODE, LEDC_HS_CH0_CHANNEL, 3000);
    ledc_update_duty(LEDC_HS_MODE, LEDC_HS_CH0_CHANNEL);
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    printf("3. LEDC set up to duty = 2000\n");
    ledc_set_duty(LEDC_HS_MODE, LEDC_HS_CH0_CHANNEL, 2000);
    ledc_update_duty(LEDC_HS_MODE, LEDC_HS_CH0_CHANNEL);
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    printf("4. LEDC set up to duty = 1000\n");
    ledc_set_duty(LEDC_HS_MODE, LEDC_HS_CH0_CHANNEL, 1000);
    ledc_update_duty(LEDC_HS_MODE, LEDC_HS_CH0_CHANNEL);
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    printf("5. LEDC set up to duty = 0\n");
    ledc_set_duty(LEDC_HS_MODE, LEDC_HS_CH0_CHANNEL, 0);
    ledc_update_duty(LEDC_HS_MODE, LEDC_HS_CH0_CHANNEL);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
}
