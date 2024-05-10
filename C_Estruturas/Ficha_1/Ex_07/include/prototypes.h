// system specific commands
#ifdef _WIN32 // assume Windows
    #define clearScreen() system("cls")
#else // assume POSIX or similar
    #define clearScreen() system("clear")
#endif

// matrixManager.c prototypes
int userMatrixRows();
int userMatrixColumns();
float **createDefaultMatrix(int row, int column, float value);
float **createUserMatrix(int row, int column);
void printMatrix(float **matrix, int row, int column);

// menuManager.c prototypes
void mainMenu();

// searchAndSortManager.c prototypes
void findNumberOfOccurrences(float **matrix, int row, int column);
void printLastOccurrence(float **matrix, int row, int column);
void printFirstOccurrence(float **matrix, int row, int column);