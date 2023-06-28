// --- system specific include path ---
#ifdef _WIN32 // assume Windows
    #include "..\includes\main_menu.h"
    #include "..\includes\utils.h"
#else // assume POSIX or similar
    #include "../includes/main_menu.h"
    #include "../includes/utils.h"
#endif
#include <stdio.h>

void (*main_menu_options[])() = {
    register_new_client, 
    remove_client, 
    list_active_clients, 
    client_management_menu, 
    sort_by_total_spent, 
    save_as_csv_menu
};

void main_menu_text() {
    clear_screen();
    printf("[1] - Register new client\n");
    printf("[2] - Remove client (deactivate card)\n");
    printf("[3] - List active clients\n");
    printf("[4] - Client management\n");
    printf("[5] - Sort by total spent\n");
    printf("[6] - Save as csv\n");
    printf("[0] - Exit\n");
    printf("\n>>> ");
}

void main_menu() {
    int option;
    do {
        main_menu_text();
        option = validate_integer();
        clear_buffer();
        if(option >= 1 && option <= 6) (*main_menu_options[option-1])();
        else if (option == 0) program_exit();
        else invalid_option();
    } while (option != 0);
}

void register_new_client() {
    clear_screen();
    printf("--- Register new client ---\n");
    insert_any_key();
}

void remove_client() {
    clear_screen();
    printf("--- Remove client (deactivate card) ---\n");
    insert_any_key();
}

void list_active_clients() {
    clear_screen();
    printf("--- List active clients ---\n");
    insert_any_key();
}

void client_management_menu() {
    clear_screen();
    printf("--- Client management ---\n");
    insert_any_key();
}

void sort_by_total_spent() {
    clear_screen();
    printf("--- Sort by total spent ---\n");
    insert_any_key();
}

void save_as_csv_menu() {
    clear_screen();
    printf("--- Save as csv ---\n");
    insert_any_key();
}