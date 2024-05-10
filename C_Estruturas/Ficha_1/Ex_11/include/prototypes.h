// system specific commands
#ifdef _WIN32 // assume Windows
    #define clearScreen() system("cls")
#else // assume POSIX or similar
    #define clearScreen() system("clear")
#endif

// arrayManager.c prototypes
int arraySize();
int* getUserArray(int size);
void printArray(int* array, int size);

// menuManager.c prototypes
void mainMenu();
void insertAnyKey();
void invalidOption();
void arraySorted();

// searchAndSortManager.c prototypes
void bubbleSortUnoptimized(int* array, int size);
void bubbleSortOptimized(int* array, int size);