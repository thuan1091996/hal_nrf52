#include <zephyr.h>
#include "hal.h"

#include <logging/log.h>
#define MODULE_NAME			        main
#define MODULE_LOG_LEVEL	        LOG_LEVEL_DBG
LOG_MODULE_REGISTER(MODULE_NAME, MODULE_LOG_LEVEL);

int hal__init()
{
    int status;
    status = __InitGPIO();
    if(status != SUCCESS)
    {
        LOG_ERR("GPIO init failed");
        return FAILURE;
    }
    status = __InitADC();
    if(status != SUCCESS)
    {
        LOG_ERR("ADC init failed");
        return FAILURE;
    }
    status = __InitPWM();
    if(status != SUCCESS)
    {
        LOG_ERR("PWM init failed");
        return FAILURE;
    }
    return SUCCESS;
}

void main(void)
{
    int status = hal__init();
    if(status != SUCCESS)
    {
        LOG_ERR("HAL init failed");
    }
    while (1)
    {
        k_msleep(300);
    }
}