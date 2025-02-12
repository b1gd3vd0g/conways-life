# Conway's Game of Life

By Devin Peevy

## Overview

This simple C program is an example of
[Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life).

For now, the zero-player game is single threaded. At the beginning of the game,
the user will be prompted to choose a width and height for the grid, and a
percent chance for a single cell to begin the game alive. The game then updates
and draws itself approximately once every second, keeping track of which tick
it is, and the percentage of living cells.

The game ends in one of two ways:

1. The grid of cells eventually stabilizes. The program will display the final
   grid, and the number of ticks it took to stabilize.

2. The user terminates the program by pressing `Ctrl+C`.

## Future Improvements

### Multithreading

I want to add a new prompt for the user, "How many threads should do the work?"
Each thread will process a portion of the grid.

Another option that I have seen is having every single cell be its own thread.
This doesn't seem like a great idea to me though, but might be interesting to
try.

### Terminal options

-   `-w | --width`: Determine the width of the grid, skip prompt in beginning.
-   `-h | --height`: Determine the height of the grid, skip prompt in beginning.
-   `-p | --percent`: Determine the initial percent of living cells, skip prompt
    in beginning
-   `-t | --threads`: Determine the number of processing threads, skip prompt in
    beginning.
-   `-s | --speed`: Determine the speed of the tick counter (in seconds per tick).
-   `--show-history`: Instead of clearing the screen each time we draw the board,
    display the entire history of the game in the terminal.

### Pattern choosing

There are some super cool configurations of the game of life that you are super
unlikely to get by a random generator. Find a way to create some initial grids
so that these patterns may be watched.
