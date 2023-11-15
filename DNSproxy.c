
#include "DNSproxy.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_config(struct dns_config *config) {
    // Зчитує конфігураційний файл та ініціалізує структуру config

    FILE *file = fopen(CONFIG_FILE, "r");
    if (file == NULL) {
        perror("Помилка відкриття конфігураційного файлу");
        exit(EXIT_FAILURE);
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        
        char *key = strtok(line, "=");
        char *value = strtok(NULL, "=");

        
        key = strtok(key, " \t\n\r");
        value = strtok(value, " \t\n\r");

        // Заповнюємо структуру config відповідно до ключів та значень
        if (strcmp(key, "upstream_dns_address") == 0) {
            strncpy(config->upstream_dns_address, value, sizeof(config->upstream_dns_address) - 1);
        } else if (strcmp(key, "blacklisted_domains") == 0) {
            // Додамо домен у "чорний" список
            strncpy(config->blacklisted_domains[0], value, sizeof(config->blacklisted_domains[0]) - 1);
        }
    }

    fclose(file);
}
