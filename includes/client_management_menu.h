#pragma once

#ifdef _WIN32 // assume Windows
    #include "..\includes\structs.h"
#else // assume POSIX or similar
    #include "../includes/structs.h"
#endif

// client management menu functions declarations
void client_management_menu_text();
void client_management_menu(Client* clients, Store* stores);
void add_purchase(Client* clients, Store* stores);
void list_purchases(Client* clients);
void purchase_details(Client* clients);
void verify_vouchers();