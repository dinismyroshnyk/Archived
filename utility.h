// --- system specific commands ---
#ifdef _WIN32 // assume Windows
    #define clear_screen() system("cls")
#else // assume POSIX or similar
    #define clear_screen() system("clear")
#endif

// prototypes
void main_menu();