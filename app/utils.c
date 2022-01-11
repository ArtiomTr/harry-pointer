#include "utils.h"

#include <ctype.h>
#include <malloc.h>
#include <string.h>

const char PAGE_EXTENSION[] = ".html";

char *getPageFromSentence(char sentence[]) {
    size_t sentenceLength = strlen(sentence);

    char *output = calloc(sentenceLength + strlen(PAGE_EXTENSION) + 1, sizeof(char));

    for(size_t i = 0; i < sentenceLength; ++i) {
        if(isspace(sentence[i])) {
            output[i] = '-';
        } else {
            output[i] = tolower(sentence[i]);
        }
    }

    strncpy(output + sentenceLength, PAGE_EXTENSION, strlen(PAGE_EXTENSION));

    return output;
}
