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
#include <time.h>
#include <string.h>

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

void client_management_menu(Client* clients, Store* stores) {
    int option;
    do
    {
        client_management_menu_text();
        option = validate_integer();
        clear_buffer();
        if(option >= 1 && option <= 5 && option != 2) (*client_management_menu_options[option-1])(clients);
        else if (option == 2) (*client_management_menu_options[option-1])(clients, stores);
        else if (option == 0) break;
        else invalid_option();
    } while (option != 0);
}

void add_purchase(Client* clients, Store* stores) {
    clear_screen();
    printf("--- Add purchase ---\n");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int client_number;
    while (1)
    {
        printf("Enter client number: ");
        client_number = validate_integer();
        clear_buffer();
        if (client_number >= 1 && client_number <= read_client_counter_from_binary()) break;
        else invalid_option();
        clear_screen();
    }
    printf("Enter purchase value: ");
    float value = validate_float();
    clear_buffer();
    if (value < 0) {
        printf("Invalid value!\n");
        insert_any_key();
        return;
    }
    if (stores == NULL) {
        printf("There are no registered stores.\n");
        insert_any_key();
        return;
    }
    while (1)
    {
        printf("Available stores:\n");
        for (Store* current = stores; current != NULL; current = current->next) {
            printf("\nName: %s", current->name);
            printf("Address: %s", current->address);
        }
        printf("Enter store name: ");
        char store_name[50];
        fgets(store_name, 50, stdin);
        for (Store* current = stores; current != NULL; current = current->next) {
            if (strcmp(current->name, store_name) == 0) {
                Purchase* new_purchase = malloc(sizeof(Purchase));
                new_purchase->value = value;
                new_purchase->day = tm.tm_mday;
                new_purchase->month = tm.tm_mon + 1;
                new_purchase->year = tm.tm_year + 1900;
                new_purchase->store = current;
                new_purchase->next = NULL;
                for (Client* current_client = clients; current_client != NULL; current_client = current_client->next) {
                    if (current_client->client_number == client_number) {
                        Purchase* current_purchase = current_client->purchases;
                        if (current_purchase == NULL) {
                            current_client->purchases = new_purchase;
                            write_client_to_binary(current_client);
                            printf("Purchase added successfully!\n");
                            insert_any_key();
                            return;
                        }
                        while (current_purchase->next != NULL) {
                            current_purchase = current_purchase->next;
                        }
                        current_purchase->next = new_purchase;
                        write_client_to_binary(current_client);
                        printf("Purchase added successfully!\n");
                        insert_any_key();
                        return;
                    }
                }
            } else {
                printf("Store not found!\n");
                insert_any_key();
                return;
            }
        }
    }
    insert_any_key();
}

void list_purchases(Client* clients) {
    clear_screen();
    printf("--- List purchases ---\n");
    int client_number;
    while (1)
    {
        printf("Enter client number: ");
        client_number = validate_integer();
        clear_buffer();
        if (client_number >= 1 && client_number <= read_client_counter_from_binary()) break;
        else invalid_option();
        clear_screen();
    }
    for (Client* current = clients; current != NULL; current = current->next) {
        if (current->client_number == client_number) {
            if (current->purchases == NULL) {
                printf("There are no purchases registered for this client.\n");
                insert_any_key();
                return;
            }
            printf("Purchases:\n");
            for (Purchase* current_purchase = current->purchases; current_purchase != NULL; current_purchase = current_purchase->next) {
                printf("Value: %.2f\n", current_purchase->value);
                printf("Date: %d/%d/%d\n", current_purchase->day, current_purchase->month, current_purchase->year);
                printf("Store: %s\n", current_purchase->store->name);
                printf("\n");
            }
            insert_any_key();
            return;
        }
    }
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