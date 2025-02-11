#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>

#include "prompter.h"
#include "cell_grid.h"

int main(int argc, char **argv)
{
    // prompt user for settings.

    int gridWidth = promptUserForPositiveInteger("Select the width of the grid.", 100);
    int gridHeight = promptUserForPositiveInteger("Select the height of the grid.", 100);
    int initialPercent = promptUserForPositiveInteger("Select the initial percent of living cells.", 100);

    // create the initial 2d array.

    int **grid = malloc(sizeof(int *) * gridHeight);
    for (int i = 0; i < gridHeight; i++)
    {
        grid[i] = malloc(sizeof(int) * gridWidth);
    }
    // load the 2d array.
    int count;
    for (int y = 0; y < gridHeight; y++)
    {
        for (int x = 0; x < gridWidth; x++)
        {
            srand(time(NULL) + count);
            int random = rand() % 100;
            grid[y][x] = (random < initialPercent) ? 1 : 0;
            count++;
        }
    }
    int tick = 0;
    double percent = initialPercent / 100.0;
    // now we forever do a loop.
    while (1)
    {
        // draw the array.
        drawCellGrid(grid, gridWidth, gridHeight, &tick, &percent);
        sleep(1);
        if (!(updateCellGrid(grid, gridWidth, gridHeight, &tick, &percent)))
        {
            // the board did not update since the last tick.
            tick--;
            break;
        }
    }
    // The grid has stabilized.
    // Tick is the number of the final tick which changed.
    printf("\nThe grid has stabilized in %d tick(s).\n", tick);
    return 0;
}