#define MAX_HTTP_RECV_BUFFER 2048
#define MAX_HTTP_OUTPUT_BUFFER 4096

#define WIFI_SSID "ESP_1"
#define WIFI_PASS "Espressif!123"
#define MAXIMUM_RETRY 10

#define TELEGRAM_HOST "api.telegram.org"
#define TELEGRAM_SSL_PORT 443
#define chat_ID2 "219745533"

void esp_tele_init(const char *ssid, const char *password);
void add_command(const char *command, void (*handler)(void));
void start_get_updates_task(void);
void bot_send_message(const char *chat_id, const char *text);