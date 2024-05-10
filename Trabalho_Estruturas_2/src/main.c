// --- system specific include path ---
#ifdef _WIN32 // assume Windows
    #include "..\includes\main_menu.h"
    #include "..\includes\structs.h"
    #include "..\includes\binary.h"
#else // assume POSIX or similar
    #include "../includes/main_menu.h"
    #include "../includes/structs.h"
    #include "../includes/binary.h"
#endif
#include <stdio.h>

int main() {
    Client* clients = NULL;
    Store* stores = NULL;
    main_menu(stores, clients);
    return 0;
}