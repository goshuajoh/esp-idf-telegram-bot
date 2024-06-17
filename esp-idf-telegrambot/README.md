# ESP-IDF Telegram Bot Component

This component allows ESP-IDF projects to interface with the Telegram Bot API. It provides functions to connect to Wi-Fi, send messages, add command handlers, and start the task to get updates from the Telegram server.

## Features

- Connect to a Wi-Fi network
- Send messages to a Telegram chat
- Add custom command handlers
- Continuously fetch updates from the Telegram server

## Getting Started

### Prerequisites

- ESP-IDF installed on your system
- Telegram Bot Token (You can create a bot and get the token from [BotFather](https://core.telegram.org/bots#6-botfather))

### Installation

1. Clone the repository or copy the component into your ESP-IDF project's components directory.

2. Add the component to your `CMakeLists.txt`:

    ```cmake
    set(EXTRA_COMPONENT_DIRS path/to/your/component)
    ```

### Example Usage

Here's a simple example demonstrating how to use the component.

```c
#include <stdio.h>
#include "esp_telebot.h"
#include "driver/gpio.h"

#define LED_GPIO GPIO_NUM_5

void led_on_handler(void)
{
    gpio_set_level(LED_GPIO, 1);
    bot_send_message("YOUR_CHAT_ID", "LED is ON");
}

void led_off_handler(void)
{
    gpio_set_level(LED_GPIO, 0);
    bot_send_message("YOUR_CHAT_ID", "LED is OFF");
}

void app_main(void)
{
    esp_tele_init("YOUR_SSID", "YOUR_PASSWORD");
    
    gpio_reset_pin(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

    add_command("/ledon", led_on_handler);
    add_command("/ledoff", led_off_handler);
    start_get_updates_task();
}


API Reference

void esp_tele_init(const char *ssid, const char *password)
Initialises the Wi-Fi connection.

ssid: The SSID of the Wi-Fi network.
password: The password of the Wi-Fi network.

void add_command(const char *command, void (*handler)(void))
Adds a command handler.

command: The command string (e.g., /ledon).
handler: The function to be called when the command is received.

void start_get_updates_task(void)
Starts the task to get updates from the Telegram server. This function should be called after adding all command handlers.

void bot_send_message(const char *chat_id, const char *text)
Sends a message to a Telegram chat.

chat_id: The chat ID to send the message to.
text: The message text.
License

This project is licensed under the MIT License - see the LICENSE file for details.

Acknowledgements

ESP-IDF
Telegram Bot API
Joshua hehe

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

Support

For any questions or issues, please open an issue on the repository or contact the maintainer.