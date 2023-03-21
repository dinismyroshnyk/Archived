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
void number_of_lines(FILE *file, char file_name[]);
void number_of_words(FILE *file, char file_name[]);
void number_of_characters(FILE *file, char file_name[]);
void number_of_user_defined_characters(FILE *file, char file_name[]);