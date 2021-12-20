#include "parseFile.h"

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "dynamicArray.h"
#include "stack.h"

#define BUFFER_SIZE 1024
#define OFFSET_SIZE 32

bool isTagCharacter(int character) {
    return isalnum(character) || isspace(character);
}

typedef struct {
    Stack tagStack;
    DynamicArray parsedTags;
    bool inString;
    bool inComment;
    bool inMultilineComment;
    bool inCharacter;
    bool inOpeningTag;
    bool inClosingTag;

    long line;
    long column;
} ParserState;

const char *processString(ParserState *state, const char *currentPtr) {
    currentPtr = strpbrk(currentPtr, "\\\"");

    if(currentPtr == NULL) {
        return currentPtr;
    }

    if(currentPtr[0] == '\"') {
        state->inString = false;
        return currentPtr + 1;
    }

    return currentPtr + 2;
}

const char *processComment(ParserState *state, const char *currentPtr) {
    currentPtr = strpbrk(currentPtr, "\\\n");

    if(currentPtr == NULL) {
        return currentPtr;
    }

    if(currentPtr[0] == '\n') {
        state->inComment = false;
        return currentPtr + 1;
    }

    return currentPtr + 2;
}

const char *processMultilineComment(ParserState *state, const char *currentPtr) {
    currentPtr = strchr(currentPtr, '*');

    if(currentPtr == NULL) {
        return currentPtr;
    }

    if(currentPtr[1] == '/') {
        state->inMultilineComment = false;

        return currentPtr + 2;
    }

    return currentPtr + 1;
}

const char *processCharacter(ParserState *state, const char *currentPtr) {
    currentPtr = strpbrk(currentPtr, "\\'");

    if(currentPtr == NULL) {
        return currentPtr;
    }

    if(currentPtr[0] == '\'') {
        state->inCharacter = false;
        return currentPtr + 1;
    }

    return currentPtr + 2;
}

const char whitespaceCharacters[] = {
        ' ',
        '\n',
        '\t',
        '\r',
        '\v',
        '\f'
};

void trimString(char *string) {
    size_t begin = strspn(string, whitespaceCharacters);
    size_t length = strlen(string);
    size_t end = begin;

    for(size_t i = length - 1; i >= begin; --i) {
        if(!isspace(string[i])) {
            end = i;
            break;
        }
    }

    string[end + 1] = '\0';

    if(begin < end && begin != 0) {
        strncpy(string, string + begin, end - begin + 1);
    }

}

const char *processClosingTag(ParserState *state, const char *currentPtr) {
    TagInfo *info = stackFront(&state->tagStack);

    if(info == NULL) {
        printf("Found closing tag without opening on line %ld column %ld", state->line, state->column);
        exit(1);
    }

    const char *beginPtr = currentPtr;

    while(beginPtr[0] != '\0' && isspace(beginPtr[0]))
        beginPtr += 1;

    const char *endPtr = beginPtr;

    while(endPtr[0] != '\0' && isalnum(endPtr[0]))
        endPtr += 1;

}

const char *processGeneral(ParserState *state, const char *currentPtr) {
    const char searchCharacters[] = {
            '\\',// escape character
            '\"',// string beginning
            '\'',// character beginning
            '/', // comment beginning
            '<', // tag beginning
    };
    currentPtr = strpbrk(currentPtr, searchCharacters);

    if(currentPtr == NULL) {
        return currentPtr;
    }

    switch(currentPtr[0]) {
        case '\\':
            return currentPtr + 2;
        case '\"':
            state->inString = true;
            return currentPtr + 1;
        case '\'':
            state->inCharacter = true;
            return currentPtr + 1;
        case '/':
            if(currentPtr[1] == '*') {
                state->inMultilineComment = true;
                return currentPtr + 2;
            } else if(currentPtr[1] == '/') {
                state->inComment = true;
                return currentPtr + 2;
            }
            return currentPtr + 1;
        case '<':
            if(currentPtr[1] == '/') {
                state->inClosingTag = true;
                return currentPtr + 2;
            } else {
                state->inOpeningTag = true;
                return currentPtr + 1;
            }
    }

    fprintf(stderr, "Error");
    exit(1);
}

void processBuffer(ParserState *state, const char *buffer) {
    const char *currentPtr = buffer;

    while(currentPtr != NULL && (currentPtr - buffer) < BUFFER_SIZE && currentPtr[0] != '\0') {
        const char* (*process)(ParserState *state, const char *buffer);

        if(state->inString) {
            process = processString;
        } else if(state->inComment) {
            process = processComment;
        } else if(state->inMultilineComment) {
            process = processMultilineComment;
        } else if(state->inCharacter) {
            process = processCharacter;
        } else if(state->inClosingTag) {
            process = processClosingTag;
        } else {
            process = processGeneral;
        }

        const char *newPtr = process(state, currentPtr);

        const char *prevNewline = NULL;

        while(true) {
            const char *nextNewline = strchr(prevNewline == NULL ? currentPtr : prevNewline, '\n');

            if(nextNewline > newPtr || nextNewline == NULL) {
                if(prevNewline != NULL) {
                    state->line += 1;
                    state->column = newPtr - prevNewline;
                } else {
                    state->column += newPtr - currentPtr;
                }

                break;
            } else {
                prevNewline = nextNewline + 1;
            }
        }

        currentPtr = newPtr;

        if(state->inOpeningTag) {
            printf("Possible tag at %ld %ld\n", state->line, state->column);
        }
    }
}

void parseFile(FILE *input) {

    long savedPosition = 0;

    int ch;

    Stack stack = createStack();
    DynamicArray array = createDynamicArray();

    ParserState state = {
            .tagStack = stack,
            .parsedTags = array,
            .inMultilineComment = false,
            .inComment = false,
            .inString = false,
            .line = 1,
            .column = 0,
    };

    char buffer[BUFFER_SIZE + 1];
    buffer[BUFFER_SIZE] = '\0';
    size_t bytesRead;

    while(1) {

        bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, input);

        processBuffer(&state, buffer);

        if(bytesRead < BUFFER_SIZE * sizeof(char)) {
            break;
        } else {
            fseek(input, -OFFSET_SIZE, SEEK_CUR);
        }
    }
}

#undef BUFFER_SIZE
#undef OFFSET_SIZE
