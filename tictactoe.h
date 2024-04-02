/* Defines */
#define COLUMNS 3
#define ROWS 3

/* Functions */
void getCoordinates(int position, int *row, int *col);
void printGame(char grid[ROWS][COLUMNS]);
int findWinner(char grid[ROWS][COLUMNS]);