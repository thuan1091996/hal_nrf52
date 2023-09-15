#include <string.h>
#include <zephyr/types.h>
#include <stddef.h>

#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <logging/log.h>
#define MODULE_NAME			        main
#define MODULE_LOG_LEVEL	        LOG_LEVEL_DBG
LOG_MODULE_REGISTER(MODULE_NAME, MODULE_LOG_LEVEL);
void main(void)
{
    while (1)
    {
        k_msleep(300);
    }
}