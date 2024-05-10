#pragma once

// structures
typedef struct Client {
    char name[50];
    int phone;
    char email[50];
    int nif;
    int client_number;
    int has_card;
    struct Card* card;
    struct Purchase* purchases;
    struct Voucher* vouchers;
    struct Client* next;
} Client;

typedef struct Card {
    float total_spent;
    int spent_vouchers;
    int purchase_counter;
} Card;

typedef struct Purchase {
    float value;
    int day;
    int month;
    int year;
    struct Store* store;
    struct Purchase* next;
} Purchase;

typedef struct Store {
    char name[50];
    char address[50];
    struct Purchase* purchases;
    struct Store* next;
} Store;

typedef struct Voucher {
    float value;
    struct Voucher* next;
} Voucher;