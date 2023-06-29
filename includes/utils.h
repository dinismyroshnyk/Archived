#pragma once
#include <stdlib.h>

// system specific commands
#ifdef _WIN32 // assume Windows
    #define clear_screen() system("cls")
#else // assume POSIX or similar
    #define clear_screen() system("clear")
#endif

// auxiliary functions declarations 
void insert_any_key();
void invalid_option();
void clear_buffer();
int validate_integer();
float validate_float();
void program_exit();