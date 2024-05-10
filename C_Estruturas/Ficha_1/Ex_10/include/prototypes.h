// system specific commands
#ifdef _WIN32 // assume Windows
    #define clearScreen() system("cls")
#else // assume POSIX or similar
    #define clearScreen() system("clear")
#endif

// defined constants
#define DEFAULT_ARRAY_SIZE 10

// arrayManager.c prototypes
int* getDefaultArray();
int arraySize();
int* getUserArray(int size);
void printArray(int* array, int size, int option);

// menuManager.c prototypes
void mainMenu();
void insertAnyKey();
void invalidOption();

// searchAndSortManager.c prototypes
void insertElementInsideSortedArray(int* array);
void insertionSort(int* array, int size);