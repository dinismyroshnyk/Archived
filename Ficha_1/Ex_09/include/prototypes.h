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

// searchAndSortManager.c prototypes
void printInedxOfLargestElement(int* array, int size);
void swapElements(int* array, int size);
void selectionSort(int* array, int size);