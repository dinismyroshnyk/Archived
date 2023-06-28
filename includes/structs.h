#pragma once

// structures
typedef struct Client {
    char name[50];
    int phone;
    char email[50];
    int nif;
    int client_number;
    struct Purchase* anonymous_purchases;
    struct Voucher* anonymous_vouchers;
    struct Client* next;
} Client;

typedef struct Purchase {
    float value;
    int day;
    int month;
    int year;
    struct Store* store;
    struct Purchase* next;
} Purchases;

typedef struct Store {
    char name[50];
    char address[50];
    struct Purchase* anonymous_purchases;
    struct Store* next;
} Store;

typedef struct Voucher {
    float value;
    struct Voucher* next;
} Vouchers;