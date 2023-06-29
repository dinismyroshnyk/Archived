#ifdef _WIN32 // assume Windows
    #include "..\includes\utils.h"
    #include "..\includes\structs.h"
    #include "..\includes\binary.h"
    #include "..\includes\edit_client_menu.h"
#else // assume POSIX or similar
    #include "../includes/utils.h"
    #include "../includes/structs.h"
    #include "../includes/binary.h"
    #include "../includes/edit_client_menu.h"
#endif
#include <stdio.h>

void (*edit_client_menu_options[])() = {
    edit_name,
    edit_phone,
    edit_email,
    edit_nif,
    reactivate_card
};

void edit_client_menu_text() {
    clear_screen();
    printf("[1] - Edit name\n");
    printf("[2] - Edit phone\n");
    printf("[3] - Edit email\n");
    printf("[4] - Edit NIF\n");
    printf("[5] - Reactivate card\n");
    printf("[0] - Cancel operation\n");
    printf("\n>>> ");
}

void edit_client_menu(Client* client) {
    clear_screen();
    int option, client_number;
    while (1)
    {
        printf("Enter client number: ");
        client_number = validate_integer();
        clear_buffer();
        if (client_number >= 1 && client_number <= read_client_counter_from_binary()) break;
        else invalid_option();
        clear_screen();
    }
    do
    {
        edit_client_menu_text();
        option = validate_integer();
        clear_buffer();
        if (option >= 1 && option <= 5) (*edit_client_menu_options[option-1])(client, client_number);
        else if (option == 0) break;
        else invalid_option();
    } while (option != 0);
}

void edit_name(Client* client, int client_number) {
    clear_screen();
    printf("--- Edit name ---\n");
    for (Client* current = client; current != NULL; current = current->next) {
        if (current->client_number == client_number) {
            printf("Current name: %s\n", current->name);
            printf("New name: ");
            fgets(current->name, 50, stdin);
            write_client_to_binary(client);
            break;
        }
    }
    insert_any_key();
}

void edit_phone() {
    clear_screen();
    printf("--- Edit phone ---\n");
    insert_any_key();
}

void edit_email() {
    clear_screen();
    printf("--- Edit email ---\n");
    insert_any_key();
}

void edit_nif() {
    clear_screen();
    printf("--- Edit NIF ---\n");
    insert_any_key();
}

void reactivate_card() {
    clear_screen();
    printf("--- Reactivate card ---\n");
    insert_any_key();
}