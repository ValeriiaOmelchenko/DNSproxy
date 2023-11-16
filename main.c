#include "DNSproxy.h"
#include <stdio.h>

int main() {
    struct dns_config config;
    read_config(&config);
    printf("Upstream DNS Address: %s\n", config.upstream_dns_address);
    printf("Blacklisted Domain: %s\n", config.blacklisted_domains[0]);
    return 0;
}
