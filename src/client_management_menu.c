#ifdef _WIN32 // assume Windows
    #include "..\includes\utils.h"
    #include "..\includes\structs.h"
    #include "..\includes\binary.h"
    #include "..\includes\edit_client_menu.h"
    #include "..\includes\client_management_menu.h"
#else // assume POSIX or similar
    #include "../includes/utils.h"
    #include "../includes/structs.h"
    #include "../includes/binary.h"
    #include "../includes/edit_client_menu.h"
    #include "../includes/client_management_menu.h"
#endif
#include <stdio.h>

void (*client_management_menu_options[])() = {
    edit_client_menu,
    add_purchase,
    list_purchases,
    purchase_details,
    verify_vouchers
};

void client_management_menu_text() {
    clear_screen();
    printf("[1] - Edit client\n");
    printf("[2] - Add purchase\n");
    printf("[3] - List purchases\n");
    printf("[4] - Purchases details\n");
    printf("[5] - Verify vouchers\n");
    printf("[0] - Back\n");
    printf("\n>>> ");
}

void client_management_menu(Client* clients) {
    int option;
    do
    {
        client_management_menu_text();
        option = validate_integer();
        clear_buffer();
        if(option >= 1 && option <= 5) (*client_management_menu_options[option-1])(clients);
        else if (option == 0) break;
        else invalid_option();
    } while (option != 0);
}

void add_purchase() {
    clear_screen();
    printf("--- Add purchase ---\n");
    insert_any_key();
}

void list_purchases() {
    clear_screen();
    printf("--- List purchases ---\n");
    insert_any_key();
}

void purchase_details() {
    clear_screen();
    printf("--- Purchase details ---\n");
    insert_any_key();
}

void verify_vouchers() {
    clear_screen();
    printf("--- Verify vouchers ---\n");
    insert_any_key();
}