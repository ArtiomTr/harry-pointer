#include "parseFile.h"

int main(int argc, char *argv[]) {
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen("out.c", "w");

    parseFile(input);

    fclose(input);
    fclose(output);

    return 0;
}