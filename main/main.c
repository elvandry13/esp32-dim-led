#include "adc1.h"

void app_main()
{
    adc_config();
    while(1)
    {
        adc_main();
    }
}
