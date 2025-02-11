/*
This function will update a single cell in the grid by counting its neighbors
and changing its state based on the rules of the game of life.

Input:
    int **grid: The grid of cells.
    int gridWidth: The width of the grid.
    int gridHeight: The height of the grid.
    int x: The x value of the cell to be updated.
    int y: The y value of the cell to be updated.

Output:
    1 if the cell was updated; else 0.
*/
int updateCell(int **grid, int gridWidth, int gridHeight, int x, int y);

/*
This function will iterate through the entire grid of cells and update them one
by one. Updates the tick counter as well.

Input:
    int **grid: The grid of cells.
    int gridWidth: The width of the grid.
    int gridHeight: The height of the grid.
    int *tick: A pointer to the tick counter.

Output:
    1 if the grid has updated at all; else 0.
*/
int updateCellGrid(int **grid, int gridWidth, int gridHeight, int *tick, double *percent);

/*
This function will clear the console and draw the cell grid (along with some
headers for additional information).

Input:
    int **grid: The grid of cells.
    int gridWidth: The width of the grid.
    int gridHeight: The height of the grid.
    int *tick: A pointer to the tick counter.

Output:
    void
*/
void drawCellGrid(int **grid, int gridWidth, int gridHeight, int *tick, double *percent);