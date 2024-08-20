#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <float.h>
#include "crypto_stats.h"


//Function to parse a single line of the CSV file

bool parse_line(char *line, CryptoData *data) {
    char *token;

    //Parse the timestamp

    token = strtok(line, ",");
    data->timestamp = atol(token);

    //Parse the open price

    token = strtok(NULL, ",");
    if (token == NULL || strcmp(token, "NaN") == 0) return false;
    data->open = atof(token);

    //Parse the high price

    token = strtok(NULL, ",");
    if (token == NULL || strcmp(token, "NaN") == 0) return false;
    data->high = atof(token);

    //Parse the low price

    token = strtok(NULL, ",");
    if (token == NULL || strcmp(token, "NaN") == 0) return false;
    data->low = atof(token);

    //Parse the close price

    token = strtok(NULL, ",");
    if (token == NULL || strcmp(token, "NaN") == 0) return false;
    data->close = atof(token);

    //Parse the volume in BTC

    token = strtok(NULL, ",");
    if (token == NULL || strcmp(token, "NaN") == 0) return false;
    data->volume_btc = atof(token);

    //Parse the volume in currency

    token = strtok(NULL, ",");
    if (token == NULL || strcmp(token, "NaN") == 0) return false;
    data->volume_currency = atof(token);

    //Parse the weighted price

    token = strtok(NULL, ",");
    if (token == NULL || strcmp(token, "NaN") == 0) return false;
    data->weighted_price = atof(token);

    return true; //Data is valid
}

void calculate_stats(CryptoData *data, int count) {
    double total_open = 0.0, total_high = 0.0, total_low = 0.0, total_close = 0.0;
    double min_open = DBL_MAX, max_open = DBL_MIN;
    double min_close = DBL_MAX, max_close = DBL_MIN;

    for (int i = 0; i < count; i++) {

        //Calculate total

        total_open += data[i].open;
        total_high += data[i].high;
        total_low += data[i].low;
        total_close += data[i].close;

        //Calculate min and max values

        if (data[i].open < min_open) min_open = data[i].open;
        if (data[i].open > max_open) max_open = data[i].open;
        if (data[i].close < min_close) min_close = data[i].close;
        if (data[i].close > max_close) max_close = data[i].close;
    }

    //Calculate averages

    double avg_open = total_open / count;
    double avg_high = total_high / count;
    double avg_low = total_low / count;
    double avg_close = total_close / count;

    //Print the results

    printf("Statistics for Cryptocurrency Data:\n");
    printf("-----------------------------------\n");
    printf("Average Open Price: %.2f\n", avg_open);
    printf("Average High Price: %.2f\n", avg_high);
    printf("Average Low Price: %.2f\n", avg_low);
    printf("Average Close Price: %.2f\n", avg_close);
    printf("Minimum Open Price: %.2f\n", min_open);
    printf("Maximum Open Price: %.2f\n", max_open);
    printf("Minimum Close Price: %.2f\n", min_close);
    printf("Maximum Close Price: %.2f\n", max_close);
}

int main() {
    FILE *file = fopen("bitstampUSD_1-min_data_2012-01-01_to_2021-03-31.csv", "r");
    if (!file) {
        perror("Unable to open file!");
        return EXIT_FAILURE;
    }

    char line[1024];
    int is_header = 1;
    int count = 0;
    int capacity = 1000; //Start with capacity for 1000 records
    CryptoData *data = malloc(capacity * sizeof(CryptoData));

    if (data == NULL) {
        perror("Memory allocation failed!");
        fclose(file);
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), file)) {

        //Skip the header row

        if (is_header) {
            is_header = 0;
            continue;
        }

        //Ensure there's enough space in the array

        if (count >= capacity) {
            capacity *= 2; // Double the capacity
            data = realloc(data, capacity * sizeof(CryptoData));
            if (data == NULL) {
                perror("Memory reallocation failed!");
                fclose(file);
                return EXIT_FAILURE;
            }
        }

        //Parse the line and check if it contains valid data

        if (parse_line(line, &data[count])) {
            count++;
        }
    }

    fclose(file);

    if (count > 0) {
        //Calculate and display statistics

        calculate_stats(data, count);
    } else {
        printf("No valid data to process.\n");
    }

    free(data); //Free the dynamically allocated memory
    return EXIT_SUCCESS;
}
