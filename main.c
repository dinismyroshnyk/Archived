// --- system specific commands ---
#ifdef _WIN32 // assume Windows
    #define clear_screen() system("cls")
#else // assume POSIX or similar
    #define clear_screen() system("clear")
#endif

// --- includes ---
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- function prototypes ---
// --- --- main menu functions --- ---
void main_menu();
void main_menu_text();
void register_new_client();
void remove_client();
void list_active_clients();
void client_management_menu();
void sort_by_total_spent();
void save_as_csv_menu();
void (*main_menu_options[])() =
{
    register_new_client, 
    remove_client, 
    list_active_clients, 
    client_management_menu, 
    sort_by_total_spent, 
    save_as_csv_menu
};
// --- --- auxiliary functions --- ---
void insert_any_key();
void invalid_option();
void clear_buffer();
int validate_integer();
float validate_float();
void program_exit();

// --- main function start ---
int main()
{
    main_menu();
    return 0;
}
// --- main function end ---

// --- auxiliary functions ---
// --- --- menu texts --- ---
void main_menu_text()
{
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

// --- --- main menu functions --- ---
void main_menu()
{
    int option;
    do
    {
        main_menu_text();
        option = validate_integer();
        clear_buffer();
        if(option >= 1 && option <= 6) (*main_menu_options[option-1])();
        else if (option == 0) program_exit();
        else invalid_option();
    } while (option != 0);
}

void register_new_client()
{
    clear_screen();
    printf("--- Register new client ---\n");
    insert_any_key();
}

void remove_client()
{
    clear_screen();
    printf("--- Remove client (deactivate card) ---\n");
    insert_any_key();
}

void list_active_clients()
{
    clear_screen();
    printf("--- List active clients ---\n");
    insert_any_key();
}

void client_management_menu()
{
    clear_screen();
    printf("--- Client management ---\n");
    insert_any_key();
}

void sort_by_total_spent()
{
    clear_screen();
    printf("--- Sort by total spent ---\n");
    insert_any_key();
}

void save_as_csv_menu()
{
    clear_screen();
    printf("--- Save as csv ---\n");
    insert_any_key();
}

// --- --- auxiliary functions --- ---
void clear_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void insert_any_key()
{
    printf("Press any key to continue...");
    getchar();
}

void invalid_option()
{
    clear_screen();
    printf("Invalid option!\n");
    insert_any_key();
}

void program_exit()
{
    clear_screen();
    printf("Exiting...\n");
    exit(0);
}

int validate_integer()
{
    int option;
    char input[50];
    scanf("%s", input);
    if (sscanf(input, "%d%*c", &option) != 1 || strlen(input) != strspn(input, "0123456789")) {
        option = -1;
    };
    return option;
}

float validate_float()
{
    float option;
    char input[50];
    scanf("%s", input);
    if (sscanf(input, "%f%*c", &option) != 1 || strlen(input) != strspn(input, "0123456789.")) {
        option = -1;
    };
    return option;
}