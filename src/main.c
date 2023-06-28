// --- system specific include path ---
#ifdef _WIN32 // assume Windows
    #include "..\includes\main_menu.h"
    # include "..\includes\structs.h"
#else // assume POSIX or similar
    #include "../includes/main_menu.h"
    #include "../includes/structs.h"
#endif

int main() {
    main_menu();
    return 0;
}