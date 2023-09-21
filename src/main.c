#include <zephyr.h>
#include "hal.h"

#include <logging/log.h>
#define MODULE_NAME			        main
#define MODULE_LOG_LEVEL	        LOG_LEVEL_DBG
LOG_MODULE_REGISTER(MODULE_NAME, MODULE_LOG_LEVEL);


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