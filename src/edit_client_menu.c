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
#include <string.h>

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

void edit_phone(Client* client, int client_number) {
    clear_screen();
    printf("--- Edit phone ---\n");
    for (Client* current = client; current != NULL; current = current->next) {
        if (current->client_number == client_number) {
            printf("Current phone: %d\n", current->phone);
            printf("New phone: ");
            current->phone = validate_integer();
            clear_buffer();
            write_client_to_binary(client);
            break;
        }
    }
    insert_any_key();
}

void edit_email(Client* client, int client_number) {
    clear_screen();
    printf("--- Edit email ---\n");
    for (Client* current = client; current != NULL; current = current->next) {
        if (current->client_number == client_number) {
            printf("Current email: %s\n", current->email);
            printf("New email: ");
            fgets(current->email, 50, stdin);
            write_client_to_binary(client);
            break;
        }
    }
    insert_any_key();
}

void edit_nif(Client* client, int client_number) {
    clear_screen();
    printf("--- Edit NIF ---\n");
    for (Client* current = client; current != NULL; current = current->next) {
        if (current->client_number == client_number) {
            printf("Current NIF: %d\n", current->nif);
            printf("New NIF: ");
            current->nif = validate_integer();
            clear_buffer();
            write_client_to_binary(client);
            break;
        }
    }
    insert_any_key();
}

void reactivate_card(Client* client, int client_number) {
    clear_screen();
    printf("--- Reactivate card ---\n");
    for (Client* current = client; current != NULL; current = current->next) {
        if (current->client_number == client_number) {
            if (current->has_card == 1) {
                printf("Card is already active\n");
                break;
            }
            else {
                current->has_card = 1;
                current->card = malloc(sizeof(Card));
                if (current->card == NULL) {
                    fprintf(stderr, "Error: function insert_new_client() failed to allocate more memory for card struct.\n");
                    exit(1);
                }
                memset(current->card, 0, sizeof(Card));
                current->vouchers = NULL;
                printf("Card reactivated.\n");
                write_client_to_binary(client);
                break;
            }
        }
    }
    insert_any_key();
}