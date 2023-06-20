// --- system specific include path ---
#ifdef _WIN32 // assume Windows
    #include "..\includes\main_menu.h"
#else // assume POSIX or similar
    #include "../includes/main_menu.h"
#endif

int main()
{
    main_menu();
    return 0;
}