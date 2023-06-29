#pragma once

#ifdef _WIN32 // assume Windows
    #include "..\includes\structs.h"
#else // assume POSIX or similar
    #include "../includes/structs.h"
#endif

// client management menu functions declarations
void client_management_menu_text();
void client_management_menu(Client* clients);
void add_purchase();
void list_purchases();
void purchase_details();
void verify_vouchers();