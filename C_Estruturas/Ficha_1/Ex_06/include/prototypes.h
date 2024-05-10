// matrixManager.c prototypes
int userMatrixRows();
int userMatrixColumns();
float **createDefaultMatrix(int row, int column, float value);
float **createUserMatrix(int row, int column);
void printMatrix(float **matrix, int row, int column);
void calculateAndPrintAverageMatrixElements(float **matrix, int row, int column);
void calculateAndPrintAverageColumnElements(float **matrix, int row, int column);
void calculateAndPrintAverageRowElements(float **matrix, int row, int column);
void calculateAndPrintNumberOfZerosAboveMainDiagonal(float **matrix, int row, int column);
void findRowWithGreatestSumOfElements(float **matrix, int row, int column);
void changePlaceOfTwoColumns(float **matrix, int row, int column);
void sumTwoMatrices(float **matrix1, int row, int column);

// menuManager.c prototypes
void mainMenu();