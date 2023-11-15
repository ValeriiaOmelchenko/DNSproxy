
#ifndef DNS_PROXY_H
#define DNS_PROXY_H

#define CONFIG_FILE "dns_proxy_config.conf"

struct dns_config {
    // Структура для збереження конфігураційних параметрів
    char upstream_dns_address[50];
    char blacklisted_domains[10][100];
};

void read_config(struct dns_config *config);

#endif // DNS_PROXY_H
