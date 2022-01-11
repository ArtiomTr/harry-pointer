#include "integrated.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int validate_name_OR_surname(char name[]) {
    for(int i = 0; i < strlen(name); ++i) {
        if(isalpha(name[i]) == 0 && name[i] != '\0') {
            printf("\nIncorrect format! You can only write letters!\n");
            return 0;
        }
    }

    return 1;
}

int validate_phone_number(char phone_number[]) {

    for(int i = 0; i < strlen(phone_number); ++i) {
        if(isdigit(phone_number[i]) == 0) {
            // pirmas elementas gali buti pliusas
            if(i == 0 && phone_number[i] == '+') {
                continue;
            }

            printf("\nIncorrect phone number format!\n"
                   "You can only write numbers and \"+\" at the start if needed!\n");
            return 0;
        }
    }

    return 1;
}

int validate_email(char email[]) {
    int eta_counter = 0;
    int eta_position;


    int dot_counter = 0;
    int dot_position;

    // ar yra tarpu arba tab'u
    int is_space = 0;


    for(int i = 0; i < strlen(email); ++i) {
        if(email[i] == '@') {
            ++eta_counter;
            eta_position = i;
        }


        if(email[i] == ' ' || email[i] == '\t') {
            ++is_space;
        }
    }


    if(is_space != 0) {
        printf("\nIncorrect format! There must not be any spaces or tabs!\n");
        return 0;
    }

    // Original code modified: condition removed, because of it function
    //   not printed error for strings not containing "@"

    // if(eta_counter != 1) {
    //     return 0;
    // }

    // turi buti tik vienas @
    if(eta_counter == 1) {
        // ar yra tekstas pries @
        if(eta_position != 0) {
            // ar po @ yra tekstas (pries taska)
            if(email[eta_position + 1] != '.') {
                for(int i = eta_position + 1; i < strlen(email); ++i) {
                    if(email[i] == '.') {
                        ++dot_counter;
                        dot_position = i;
                    }
                }

            } else {
                printf("\nIncorrect format! Something must be written after the \"@\" symbol and before the dot!\n");
                return 0;
            }

        } else {
            printf("\nIncorrect format! Something must be written before the \"@\" symbol!\n");
            return 0;
        }
    } else {
        printf("\nIncorrect format! There should be exactly one \"@\" symbol!\n");
        return 0;
    }


    if(dot_counter == 1) {
        // po tasko turi buti kazkas parasyta
        if(dot_position != strlen(email) - 1) {
            return 1;
        } else {
            printf("\nIncorrect format! Something must be written after a dot!\n");
            return 0;
        }

    } else if(dot_counter > 1) {
        int dots[dot_counter];

        // ar po kiekvieno tasko(isskyrus paskutini) yra kazkas parasyta
        for(int i = 0; i < dot_counter - 1; ++i) {
            if(dots[i] == dots[i + 1]) {
                printf("\nIncorrect format! Something must be written after each dot!\n");
                return 0;
            }
        }

        // ar po paskutinio tasko yra kazkas parasyta
        if(dots[dot_counter - 1] != strlen(email) - 1) {
            return 1;
        } else {
            printf("\nIncorrect format! Something must be written after each dot!\n");
            return 0;
        }

    } else {
        printf("\nIncorrect format! A dot should be after the \"@\" symbol!\n");
        return 0;
    }
}