#include "input.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "integrated.h"

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

void runScanner(int (*scanner)(FILE *input, void *output, const void *options),
                FILE *input,
                void *output,
                const void *options) {
    for(int i = 0; i < MAX_RETRY_COUNT; ++i) {
        int scanResult = scanner(input, output, options);

        clearBuffer(input);

        if(scanResult == 0) {
            return;
        }
    }
    printf("Too many attempts\n");
    exit(1);
}

typedef struct {
    size_t length;
    const char *prefix;
    bool optional;
} StringScannerOptions;

int scanStringFn(FILE *input, char *output, StringScannerOptions *options) {
    memset(output, '\0', options->length);

    printf("%s (%ld characters): ", options->prefix, options->length - 1);

    char *format = calloc(100, sizeof(char));

    sprintf(format, "%%%ld[^\n]", options->length - 1);

    fscanf(input, format, output);

    free(format);
    trimString(output);
    if(!options->optional && strlen(output) == 0) {
        printf("Input cannot be empty\n");
        return -1;
    }

    return 0;
}

void scanString(FILE *input, char *output, size_t length, const char *prefix, bool optional) {
    StringScannerOptions options = {
            .prefix = prefix,
            .length = length,
            .optional = optional,
    };

    runScanner(scanStringFn, input, output, &options);
}

int scanTitleFn(FILE *input, char *output, StringScannerOptions *options) {
    int scanResult = scanStringFn(input, output, options);

    if(scanResult != 0) {
        return scanResult;
    }

    if(!validate_name_OR_surname(output)) {
        return -1;
    }

    return 0;
}

void scanTitle(FILE *input, char *output, size_t length, const char *prefix) {

    StringScannerOptions options = {
            .prefix = prefix,
            .length = length,
            .optional = false,
    };

    runScanner(scanTitleFn, input, output, &options);
}

int scanPhoneFn(FILE *input, char *output, StringScannerOptions *options) {
    int status = scanStringFn(input, output, options);
    if(status != 0) {
        return status;
    }

    if(!validate_phone_number(output)) {
        return -1;
    }

    return 0;
}

void scanPhone(FILE *input, char *output, size_t length, const char *prefix) {
    StringScannerOptions options = {
            .prefix = prefix,
            .length = length,
            .optional = false,
    };

    runScanner(scanPhoneFn, input, output, &options);
}

int scanEmailFn(FILE *input, char *output, StringScannerOptions *options) {
    int status = scanStringFn(input, output, options);
    if(status != 0) {
        return status;
    }

    if(!validate_email(output)) {
        return -1;
    }

    return 0;
}

void scanEmail(FILE *input, char *output, size_t length, const char *prefix) {
    StringScannerOptions options = {
            .prefix = prefix,
            .length = length,
            .optional = false,
    };

    runScanner(scanEmailFn, input, output, &options);
}

int scanPositiveIntFn(FILE *input, int *output, const char *prefix) {
    printf("%s: ", prefix);
    fscanf(input, "%d", output);
    int postfix = fgetc(input);
    ungetc(postfix, input);
    if(isspace(postfix) && *output > 0) {
        return 0;
    } else if(*output <= 0) {
        printf("The number cannot be negative or zero\n");
    } else {
        printf("Expected positive number as input\n");
    }

    return -1;
}

void scanPositiveInt(FILE *input, int *output, const char *prefix) {
    runScanner(scanPositiveIntFn, input, output, prefix);
}

int scanPositiveDoubleFn(FILE *input, double *output, const char *prefix) {
    printf("%s: ", prefix);
    fscanf(input, "%lf", output);
    int postfix = fgetc(input);
    ungetc(postfix, input);
    if(isspace(postfix) && *output > 0) {
        return 0;
    } else if(*output <= 0) {
        printf("The double cannot be negative or zero\n");
    } else {
        printf("Expected positive double as input\n");
    }

    return -1;
}

void scanPositiveDouble(FILE *input, double *output, const char *prefix) {
    runScanner(scanPositiveDoubleFn, input, output, prefix);
}

int scanImageFn(FILE *input, char *output, StringScannerOptions *options) {
    int scanResult = scanStringFn(input, output, options);

    if(scanResult != 0) {
        return scanResult;
    }

    if(strlen(output) == 0) {
        return 0;
    }

    FILE *checkFile = fopen(output, "r");

    if(checkFile == NULL) {
        printf("File \"%s\" does not exist.\n", output);
        return -1;
    }

    fclose(checkFile);

    return 0;
}

void scanImage(FILE *input, char *output, size_t length, const char *prefix) {
    StringScannerOptions options = {
            .length = length,
            .prefix = prefix,
            .optional = true,
    };

    runScanner(scanImageFn, input, output, &options);
}

ShopInfo readUserInput(FILE *input) {
    ShopInfo sInfo;

    printf("Please, enter information about your shop.\n"
           "Shop title, contact email, phone, and product titles should not be longer than 30 characters.\n");

    scanTitle(input, sInfo.shopTitle, 31, "Shop title");
    scanEmail(input, sInfo.contactEmail, 31, "Contact email");
    scanPhone(input, sInfo.contactPhone, 31, "Contact phone");
    scanPositiveInt(input, &(sInfo.categoryCount), "Count of categories");

    sInfo.categories = calloc(sInfo.categoryCount, sizeof(Category));

    for(int categoryIndex = 0; categoryIndex < sInfo.categoryCount; ++categoryIndex) {
        scanTitle(input, sInfo.categories[categoryIndex].title, 31, "Category name");
        scanString(input, sInfo.categories[categoryIndex].description, 101, "Category description", true);
        scanImage(input, sInfo.categories[categoryIndex].image, 101, "Category image");
        scanPositiveInt(input, &(sInfo.categories[categoryIndex].productCount), "Product count in category");

        sInfo.categories[categoryIndex].products =
                calloc(sInfo.categories[categoryIndex].productCount, sizeof(Product));
        for(int productIndex = 0; productIndex < sInfo.categories[categoryIndex].productCount; ++productIndex) {
            scanTitle(input, sInfo.categories[categoryIndex].products[productIndex].title, 31, "Product name");
            scanString(input,
                       sInfo.categories[categoryIndex].products[productIndex].description,
                       101,
                       "Product description",
                       true);
            scanImage(input, sInfo.categories[categoryIndex].products[productIndex].image, 101, "Product image");
            scanPositiveDouble(input, &(sInfo.categories[categoryIndex].products[productIndex].price), "Product price");
        }
    }

    return sInfo;
}