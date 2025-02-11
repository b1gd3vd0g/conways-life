#include <stdio.h>
#include <stdlib.h>

int updateCell(int **grid, int gridWidth, int gridHeight, int x, int y)
{
    int updated = 0;
    int neighbors = 0;
    for (int i = x - 1; i <= x + 1; i++)
    {
        // We know that if i is less than 0 or greater than or equal to gridWidth,
        // then it is not a part of the grid.
        if (i < 0 || i >= gridWidth)
        {
            continue;
        }
        for (int j = y - 1; j <= y + 1; j++)
        {
            // We know that if j is less than 0 or greater than or equal to gridHeight,
            // then it is not a part of the grid.
            if (j < 0 || j >= gridHeight)
            {
                continue;
            }
            // We cannot count ourselves as a neighbor.
            if (i == x && j == y)
            {
                continue;
            }
            if (grid[j][i])
            {
                neighbors++;
            }
        }
    }
    int living = grid[y][x];
    if (living)
    {
        // You just need to die if neighbors < 2 || neighbors > 3
        if (neighbors < 2 || neighbors > 3)
        {
            grid[y][x] = 0;
            updated = 1;
        }
    }
    else
    {
        // you are dead.
        // be born if you have three neighbors.
        if (neighbors == 3)
        {
            grid[y][x] = 1;
            updated = 1;
        }
    }
    return updated;
}

int updateCellGrid(int **grid, int gridWidth, int gridHeight, int *tick, double *percent)
{
    int livingCells = 0;
    int updated = 0;
    for (int y = 0; y < gridHeight; y++)
    {
        for (int x = 0; x < gridWidth; x++)
        {
            // Examine every cell to see if it changes.
            if (updateCell(grid, gridWidth, gridHeight, x, y))
            {
                updated = 1;
            }
            // The cell has been updated. Now increment livingCells if necessary.
            if (grid[y][x])
            {
                livingCells++;
            }
        }
    }
    *tick = *tick + 1;
    // We know how many living cells there are.
    *percent = (double)livingCells / (gridHeight * gridWidth);
    return updated;
}

void drawCellGrid(int **grid, int gridWidth, int gridHeight, int *tick, double *percent)
{
    system("clear");
    printf("Conway's Game of Life\n");
    printf("Width: %d | Height: %d\n", gridWidth, gridHeight);
    printf("Tick %d | %% living: %.2f\n", *tick, *percent * 100);
    for (int y = 0; y < gridHeight; y++)
    {
        for (int x = 0; x < gridWidth; x++)
        {
            printf("%c ", grid[y][x] ? 'X' : ' ');
        }
        printf("\n");
    }
}