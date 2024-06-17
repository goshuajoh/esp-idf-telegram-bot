#include "ESP_IDF_telebot.h"
#include "driver/gpio.h"

#define BOOT_BUTTON_GPIO GPIO_NUM_0
#define LED_GPIO GPIO_NUM_5

void led_on_handler(void)
{
    gpio_set_level(GPIO_NUM_5, 1);
    bot_send_message("219745533", "Led is ON");
}

void led_off_handler(void)
{
    gpio_set_level(GPIO_NUM_5, 0);
    bot_send_message("219745533", "Led is OFF");
}

void app_main(void)
{
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_NEGEDGE;
    io_conf.pin_bit_mask = (1ULL << BOOT_BUTTON_GPIO);
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    gpio_config(&io_conf);

    esp_rom_gpio_pad_select_gpio(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_level(LED_GPIO, 0);
    esp_tele_init("ESP_1", "Espressif!123");
    add_command("/ledon", led_on_handler);
    add_command("/ledoff", led_off_handler);
    add_command("/status", led_on_handler); // You can add a proper status handler here
    start_get_updates_task();
}
