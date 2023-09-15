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