// system specific commands
#ifdef _WIN32 // assume Windows
    #define clearScreen() system("cls")
#else // assume POSIX or similar
    #define clearScreen() system("clear")
#endif