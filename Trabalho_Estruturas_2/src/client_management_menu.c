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
    int client_counter = read_client_counter_from_binary();
    while (1) {
        printf("Enter client number: ");
        client_number = validate_integer();
        clear_buffer();
        if (client_number >= 1 && client_number <= client_counter) {
            break;
        } else {
            invalid_option();
            clear_screen();
        }
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
    printf("Available stores:\n");
    for (Store* current = stores; current != NULL; current = current->next) {
        printf("\nName: %s", current->name);
        printf("\nAddress: %s", current->address);
    }
    printf("\nEnter store name: ");
    char store_name[50];
    fgets(store_name, 50, stdin);
    store_name[strcspn(store_name, "\n")] = 0;
    Store* selected_store = NULL;
    for (Store* current = stores; current != NULL; current = current->next) {
        if (strcmp(current->name, store_name) == 0) {
            selected_store = current;
            break;
        }
    }
    if (selected_store == NULL) {
        printf("Store not found!\n");
        insert_any_key();
        return;
    }
    Purchase* new_purchase = malloc(sizeof(Purchase));
    new_purchase->value = value;
    new_purchase->day = tm.tm_mday;
    new_purchase->month = tm.tm_mon + 1;
    new_purchase->year = tm.tm_year + 1900;
    new_purchase->store = selected_store;
    new_purchase->next = NULL;
    Client* selected_client = NULL;
    for (Client* current_client = clients; current_client != NULL; current_client = current_client->next) {
        if (current_client->client_number == client_number) {
            current_client->card->total_spent += value;
            current_client->card->purchase_counter += 1;
            selected_client = current_client;
            break;
        }
    }
    if (selected_client == NULL) {
        printf("Client not found!\n");
        insert_any_key();
        return;
    }
    if (selected_client->has_card) {
        Voucher* current_voucher = selected_client->vouchers;
        if (current_voucher != NULL) {
            printf("You have a voucher with a value of %.2f. Do you want to use it to discount this purchase? (y/n)\n", current_voucher->value);
            char answer;
            scanf("%c", &answer);
            clear_buffer();
            if (answer == 'y') {
                if (value < current_voucher->value) {
                    printf("The purchase value is lower than the voucher discount. The voucher cannot be used.\n");
                } else {
                    value -= current_voucher->value;
                    new_purchase->value = value;
                    selected_client->card->total_spent -= current_voucher->value;
                    selected_client->card->spent_vouchers += 1;
                    Voucher* temp = current_voucher;
                    selected_client->vouchers = current_voucher->next;
                    free(temp);
                    printf("Voucher used successfully!\n");
                }
            }
        }
    }
    Purchase* current_purchase = selected_client->purchases;
    if (current_purchase == NULL) {
        selected_client->purchases = new_purchase;
    } else {
        while (current_purchase->next != NULL) {
            current_purchase = current_purchase->next;
        }
        current_purchase->next = new_purchase;
    }
    write_client_to_binary(selected_client);
    printf("Purchase added successfully!\n");
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

void purchase_details(Client* clients) {
    clear_screen();
    printf("--- Purchase details ---\n");
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
            printf("Total spent: %.2f\n", current->card->total_spent);
            printf("Spent vouchers: %d\n", current->card->spent_vouchers);
            printf("Average spent: %.2f\n", current->card->total_spent / current->card->purchase_counter);
            insert_any_key();
            return;
        }
    }
}

void verify_vouchers() {
    clear_screen();
    printf("--- Verify vouchers ---\n");
    insert_any_key();
}