// --- system specific include path ---
#ifdef _WIN32 // assume Windows
    #include "..\includes\structs.h"
    #include "..\\includes\\binary.h"
#else // assume POSIX or similar
    #include "../includes/structs.h"
    #include "../includes/binary.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void write_store_to_binary(Store* stores) {
    FILE *file = fopen("stores.bin", "wb");
    if (file == NULL) {
        fprintf(stderr, "Error: function write_store_to_binary() failed to open file.\n");
        exit(1);
    }
    Store* current_store = stores;
    while (current_store != NULL) {
        fwrite(current_store, sizeof(Store), 1, file);
        current_store = current_store->next;
    }
    fclose(file);
}

Store* read_store_from_binary() {
    FILE *file = fopen("stores.bin", "rb");
    if (file == NULL) {
        fprintf(stderr, "Warning: function read_store_from_binary() failed to open file.\n");
        return NULL;
    }
    Store* store_list = NULL;
    Store* current_store = NULL;
    while (1) {
        Store* new_store = malloc(sizeof(Store));
        if (fread(new_store, sizeof(Store), 1, file) != 1) {
            free(new_store);
            break;
        }
        new_store->next = NULL;
        if (store_list == NULL) {
            store_list = new_store;
            current_store = new_store;
        } else {
            current_store->next = new_store;
            current_store = new_store;
        }
    }
    fclose(file);
    return store_list;
}

int read_client_counter_from_binary() {
    FILE *file = fopen("client_counter.bin", "rb");
    if (file == NULL) return 0;
    int client_counter;
    fread(&client_counter, sizeof(int), 1, file);
    fclose(file);
    return client_counter;
}

void write_client_counter_to_binary(int client_counter) {
    FILE *file = fopen("client_counter.bin", "wb");
    if (file == NULL) {
        fprintf(stderr, "Error: function write_client_counter_to_binary() failed to open file.\n");
        exit(1);
    }
    fwrite(&client_counter, sizeof(int), 1, file);
    fclose(file);
}

void write_client_to_binary(Client* clients) {
    FILE *file = fopen("clients.bin", "wb");
    if (file == NULL) {
        fprintf(stderr, "Error: function write_client_to_binary() failed to open file.\n");
        exit(1);
    }
    Client* current_client = clients;
    while (current_client != NULL) {
        fwrite(current_client, sizeof(Client), 1, file);
        current_client = current_client->next;
    }
    fclose(file);
}

Client* read_client_from_binary() {
    FILE* file = fopen("clients.bin", "rb");
    if (file == NULL) {
        fprintf(stderr, "Warning: function read_client_from_binary() failed to open file.\n");
        return NULL;
    }
    Client* client_list = NULL;
    Client* current_client = NULL;
    while (1) {
        Client* new_client = malloc(sizeof(Client));
        if (fread(new_client, sizeof(Client), 1, file) != 1) {
            free(new_client);
            break;
        }
        new_client->next = NULL;
        if (client_list == NULL) {
            client_list = new_client;
            current_client = new_client;
        } else {
            current_client->next = new_client;
            current_client = new_client;
        }
    }
    fclose(file);
    return client_list;
}

