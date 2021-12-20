#include "input.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_RETRY_COUNT = 5;

void clearBuffer(FILE *input) {
    fscanf(input, "%*[^\n]");
    fscanf(input, "%*c");
}

void trimString(char *string) {
    size_t begin = 0;
    size_t end = strlen(string);
    for(size_t i = 0; i < strlen(string); ++i) {
        if(!isspace(string[i])) {
            begin = i;
            break;
        }
    }
    for(size_t i = strlen(string) - 1; i >= 0; --i) {
        if(!isspace(string[i])) {
            end = i + 1;
            break;
        }
    }
    string[end] = '\0';
    if((end > begin) && (begin != 0)) {
        memmove(string, string + begin, end - begin + 1);
    }
}

void scanTitle(FILE *input, char *output, const char *prefix) {

    for(int i = 0; i < MAX_RETRY_COUNT; ++i) {
        printf("%s", prefix);
        fscanf(input, "%30[^\n]", output);
        trimString(output);
        if(strlen(output) == 0) {
            printf("Input cannot be empty\n");
        } else {
            return;
        }
        clearBuffer(input);
    }
    printf("Too many attempts\n");
    exit(1);
}

void scanPositiveInt(FILE *input, int *output, const char *prefix) {
    for(int i = 0; i < MAX_RETRY_COUNT; ++i) {
        printf("%s", prefix);
        fscanf(input, "%d", output);
        int postfix = fgetc(input);
        if(isspace(postfix) && *output > 0) {
            return;
        } else if(*output <= 0) {
            printf("The number cannot be negative or zero\n");
        } else {
            printf("Input a number\n");
        }
        ungetc(postfix, input);
        clearBuffer(input);
    }
    printf("Too many attempts\n");
    exit(1);
}

ShopInfo readUserInput(FILE *file) {
    ShopInfo sInfo;

    sInfo.shopTitle = calloc(30, sizeof(char));
    scanTitle(file, sInfo.shopTitle, "Shop Title: ");
    scanPositiveInt(file, &(sInfo.productCount), "Product Count: ");
    sInfo.products = calloc(sInfo.productCount, sizeof(Product));
    for(int i = 0; i < sInfo.productCount; ++i) {
        sInfo.products[i].title = calloc(30, sizeof(char));
        scanTitle(file, sInfo.products[i].title, "Product Title: ");
        scanPositiveInt(file, &(sInfo.products[i].price), "Product Price: ");
    }

    return sInfo;
}