idf_component_register(SRCS "ESP_IDF_Telebot.c"
                    INCLUDE_DIRS "include"
                    REQUIRES esp_wifi nvs_flash esp_http_server json esp_http_client esp_timer esp_driver_gpio esp_driver_ledc esp_adc esp_psram driver esp-tls
                    EMBED_TXTFILES telegram_certificate.pem)
