// --- system specific include path ---
#ifdef _WIN32 // assume Windows
    #include "..\includes\main_menu.h"
    #include "..\includes\utils.h"
    #include "..\includes\structs.h"
    #include "..\includes\binary.h"
    #include "..\includes\client_management_menu.h"
#else // assume POSIX or similar
    #include "../includes/main_menu.h"
    #include "../includes/utils.h"
    #include "../includes/structs.h"
    #include "../includes/binary.h"
    #include "../includes/client_management_menu.h"
#endif
#include <stdio.h>
#include <string.h>

void (*main_menu_options[])() = {
    register_new_client, 
    remove_client, 
    list_active_clients, 
    client_management_menu,
    register_new_store,
    remove_store,
    sort_by_total_spent, 
    save_as_csv_menu
};

void main_menu_text() {
    clear_screen();
    printf("[1] - Register new client\n");
    printf("[2] - Remove client (deactivate card)\n");
    printf("[3] - List active clients\n");
    printf("[4] - Client management\n");
    printf("[5] - Register new store\n");
    printf("[6] - Remove store\n");
    printf("[7] - Sort by total spent\n");
    printf("[8] - Save as csv\n");
    printf("[0] - Exit\n");
    printf("\n>>> ");
}

void main_menu(Store* stores, Client* clients) {
    int option;
    do {
        stores = read_store_from_binary();
        clients = read_client_from_binary();
        main_menu_text();
        option = validate_integer();
        clear_buffer();
        if((option >= 1 && option <= 3) || (option >= 6 && option <= 8)) (*main_menu_options[option-1])(clients);
        else if (option == 5) (*main_menu_options[option-1])(stores);
        else if (option == 4) (*main_menu_options[option-1])(clients, stores);
        else if (option == 0) program_exit();
        else invalid_option();
    } while (option != 0);
}

void register_new_client(Client* clients) {
    clear_screen();
    printf("--- Register new client ---\n");
    int counter = read_client_counter_from_binary();
    char answer;
    Client* new_client = malloc(sizeof(Client));
    if (new_client == NULL) {
        fprintf(stderr, "Error: function insert_new_client() failed to allocate more memory.\n");
        exit(1);
    }
    printf("Client name: ");
    fgets(new_client->name, 50, stdin);
    printf("Client phone: ");
    new_client->phone = validate_integer();
    clear_buffer();
    printf("Client email: ");
    fgets(new_client->email, 50, stdin);
    printf("Client NIF: ");
    new_client->nif = validate_integer();
    clear_buffer();
    while (1) {
        printf("The client has a card? (y/n) ");
        scanf("%c", &answer);
        if (answer == 'y' || answer == 'Y') 
        {
            new_client->has_card = 1;
            new_client->client_number = ++counter;
            new_client->card = malloc(sizeof(Card));
            if (new_client->card == NULL) {
                fprintf(stderr, "Error: function insert_new_client() failed to allocate more memory for card struct.\n");
                exit(1);
            }
            memset(new_client->card, 0, sizeof(Card));
            //new_client->vouchers = NULL;
            // teste de vouchers
            new_client->vouchers = malloc(sizeof(Voucher));
            if (new_client->vouchers == NULL) {
                fprintf(stderr, "Error: function insert_new_client() failed to allocate more memory for voucher struct.\n");
                exit(1);
            }
            new_client->vouchers->value = 5;
            new_client->vouchers->next = NULL;
            // fim teste de vouchers
            clear_buffer();
            break;
        }
        if (answer == 'n' || answer == 'N') 
        {
            new_client->has_card = 0;
            new_client->client_number = ++counter;
            new_client->card = NULL;
            new_client->vouchers = NULL;
            clear_buffer();
            break;
        }
        else printf("Invalid answer. Please try again.\n");
    };
    new_client->next = NULL;
    if (clients == NULL) {
        clients = new_client;
    } else {
        Client* current = clients;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_client;
    }
    write_client_to_binary(clients);
    write_client_counter_to_binary(counter);
    insert_any_key();
}

void remove_client(Client* clients) {
    clear_screen();
    printf("--- Remove client (deactivate card) ---\n");
    printf("Insert client number: ");
    int client_number = validate_integer();
    clear_buffer();
    if (clients == NULL) printf("There are no registered clients.\n");
    else {
        for (Client* current = clients; current != NULL; current = current->next) {
            if (current->client_number == client_number) {
                if (current->has_card == 0) {
                    printf("Client does not have a card.\n");
                    break;
                }
                else {
                    current->has_card = 0;
                    if (current->card != NULL) {
                        free(current->card);
                        current->card = NULL;
                    }
                    write_client_to_binary(clients);
                    printf("Client card deactivated.\n");
                    break;
                }
            }
        }
    }
    insert_any_key();
}

void list_active_clients(Client* clients) {
    clear_screen();
    printf("--- List active clients ---\n");
    if (clients == NULL) printf("There are no active clients.\n");
    else {
        for (Client* current = clients; current != NULL; current = current->next) {
            if (current->has_card == 1) {
                printf("Client name: %s", current->name);
                printf("Client phone: %d\n", current->phone);
                printf("Client email: %s", current->email);
                printf("Client NIF: %d\n", current->nif);
                printf("Client number: %d\n", current->client_number);
                printf("\n");
            }
        }
    }
    insert_any_key();
}

void register_new_store(Store* stores) {
    clear_screen();
    printf("--- Register new store ---\n");
    Store* new_store = malloc(sizeof(Store));
    if (new_store == NULL) {
        fprintf(stderr, "Error: function insert_new_store() failed to allocate more memory.\n");
        exit(1);
    }
    printf("Store name: ");
    fgets(new_store->name, 50, stdin);
    new_store->name[strlen(new_store->name)-1] = '\0';
    printf("Store address: ");
    fgets(new_store->address, 50, stdin);
    new_store->address[strlen(new_store->address)-1] = '\0';
    new_store->purchases = NULL; // overwrites the old stores for some reason
    new_store->next = NULL;
    if (stores == NULL) {
        stores = new_store;
    } else {
        Store* current = stores;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_store;
    }
    write_store_to_binary(stores);
    insert_any_key();
}

void remove_store() { // temporarily to test the binary file
    clear_screen();
    printf("--- Remove store ---\n");
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