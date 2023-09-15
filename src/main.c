#include <string.h>
#include <zephyr/types.h>
#include <stddef.h>

#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <logging/log.h>

#define MODULE_NAME			        main
#define MODULE_LOG_LEVEL	        LOG_LEVEL_DBG
LOG_MODULE_REGISTER(MODULE_NAME, MODULE_LOG_LEVEL);


#define APP_TEST_BLE            (1)
#define APP_TEST_PWM            (0)


#if (APP_TEST_BLE != 0)
#include "ble\ble_gatt.h"
#include "ble\bluetoothle.h"

void* char1_read_cb(void* p_data, void* p_len)
{
    static char default_char_value[]="CHAR1_PAYLOAD";
    *(int*)p_len = strlen(default_char_value);
    return default_char_value;
}

void* char2_read_cb(void* p_data, void* p_len)
{
    static char default_char_value[]="CHAR2_PAYLOAD";
    *(int*)p_len = strlen(default_char_value);
    return default_char_value;
}

void* char3_read_cb(void* p_data, void* p_len)
{
    static char default_char_value[]="CHAR3_PAYLOAD";
    *(int*)p_len = strlen(default_char_value);
    return default_char_value;
}

void* char4_read_cb(void* p_data, void* p_len)
{
    static char default_char_value[]="CHAR4_PAYLOAD";
    *(int*)p_len = strlen(default_char_value);
    return default_char_value;
}

int char5_write_cb(void* p_data, void* p_len)
{
    // Dump receive data
    LOG_INF("char5_write_cb, recv %dB", *(int*)p_len);
    LOG_HEXDUMP_INF(p_data, *(int*)p_len, "raw_payload: ");
    return 0;
}

ble_custom_gatt_cb_t custom_service_app =
{
    .custom_char1_read_cb = &char1_read_cb,
    .custom_char2_read_cb = &char2_read_cb,
    .custom_char3_read_cb = &char3_read_cb,
    .custom_char4_read_cb = &char4_read_cb,
    .custom_char5_write_cb = &char5_write_cb,
};

void ble_test(void)
{
    LOG_INF("============== BLE testing =====================");
    ble_init(NULL);
    ble_custom_service_init(&custom_service_app);

    ble_set_adv_name("ITACHI-BLE");
    ble_adv_start();
    while(1)
    {
        k_msleep(500);
        char3_send_notify("HELLO THERE, IM 3", strlen("HELLO THERE, IM 3"));
        k_msleep(500);
        char4_send_notify("HELLO THERE, IM 4", strlen("HELLO THERE, IM 4"));
    }
    LOG_INF("============== BLE testing =====================");
}
#endif /* End of (APP_TEST_BLE != 0) */

#if (APP_TEST_PWM != 0)
int __InitPWM();
int hal__setDutyCycle(uint8_t channel_num, uint16_t dutyCycle_tenth);

void pwm_custom_task(void *pvParameters)
{
    __InitPWM();
    while(1)
    {
        // Test PWM APIS with max duty = 1000%
        // Increase the duty cycle of each pin 50% every 300ms
        for(uint16_t duty = 0; duty <= 1000; duty += 10)
        {
            hal__setDutyCycle(0, duty);
            hal__setDutyCycle(1, duty);
            hal__setDutyCycle(2, duty);
            hal__setDutyCycle(3, duty);
            k_msleep(500);
            if(duty == 1000)
            {
                k_msleep(2000);
                duty = 0;
            }
            else if(duty == 0)
                k_msleep(2000);
        }
    }
}
#endif /* End of (APP_TEST_PWM != 0) */

void main(void)
{
#if (APP_TEST_BLE != 0)
    ble_test();
#endif /* End of (APP_TEST_BLE != 0) */

    while (1)
    {
        k_msleep(300);
    }
}