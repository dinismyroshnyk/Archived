// system specific commands
#ifdef _WIN32 // assume Windows
    #define clear_screen() system("cls")
#else // assume POSIX or similar
    #define clear_screen() system("clear")
#endif

// definitions
#define FILE_DIR "Ficha_2\\Docs\\"

// menuManager headers
void main_menu();
void insert_any_key();
void invalid_option();

// fileManager headers
void create_file(FILE *file, char file_name[], char file_content[]);
void append_data_to_file(FILE *file, char file_name[], char file_content[]);
void print_content_to_console(FILE *file, char file_name[]);