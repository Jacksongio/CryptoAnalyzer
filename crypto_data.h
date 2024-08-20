//crypto_data.h
#ifndef CRYPTO_DATA_H
#define CRYPTO_DATA_H

#include <stdbool.h>

//Define a structure to hold a single row of data

typedef struct {
    long timestamp;
    double open;
    double high;
    double low;
    double close;
    double volume_btc;
    double volume_currency;
    double weighted_price;
} CryptoData;

//Function prototypes

bool parse_line(char *line, CryptoData *data);
void calculate_stats(CryptoData *data, int count);

#endif //CRYPTO_DATA_H
