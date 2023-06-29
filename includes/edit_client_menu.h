#pragma once

#ifdef _WIN32 // assume Windows
    #include "..\includes\structs.h"
#else // assume POSIX or similar
    #include "../includes/structs.h"
#endif

// edit client menu functions declarations
void edit_client_menu_text();
void edit_client_menu(Client* client);
void edit_name(Client* client, int client_number);
void edit_phone(Client* client, int client_number);
void edit_email(Client* client, int client_number);
void edit_nif(Client* client, int client_number);
void reactivate_card(Client* client, int client_number);