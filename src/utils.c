// --- system specific include path ---
#ifdef _WIN32 // assume Windows
    #include "..\includes\utils.h"
#else // assume POSIX or similar
    #include "../includes/utils.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void insert_any_key() {
    printf("Press any key to continue...");
    getchar();
}

void invalid_option() {
    clear_screen();
    printf("Invalid option!\n");
    insert_any_key();
}

void program_exit() {
    clear_screen();
    printf("Exiting...\n");
    exit(0);
}

int validate_integer() {
    int option;
    char input[50];
    scanf("%s", input);
    if (sscanf(input, "%d%*c", &option) != 1 || strlen(input) != strspn(input, "0123456789")) {
        option = -1;
    };
    return option;
}

float validate_float() {
    float option;
    char input[50];
    scanf("%s", input);
    if (sscanf(input, "%f%*c", &option) != 1 || strlen(input) != strspn(input, "0123456789.")) {
        option = -1;
    };
    return option;
}