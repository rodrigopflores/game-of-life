#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_ROWS 20
#define NUMBER_OF_COLUMNS 20

int grid[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS] = {0};

void addDot(int row, int column);
void removeDot(int row, int column);
void displayGrid();
void nextFrame();

int main(void)
{
    addDot(2, 1);
    addDot(3, 2);
    addDot(3, 3);
    addDot(2, 3);
    addDot(1, 3);
    for (int i = 0; i < 20; i++)
    {
        displayGrid();
        nextFrame();
    }

    return 0;
}

void displayGrid()
{
    for (int row = 0; row < NUMBER_OF_ROWS; ++row)
    {
        printf("|");
        for (int column = 0; column < NUMBER_OF_COLUMNS; column++)
        {
            printf("%c|", (grid[row][column]) ? 'X' : ' ');
        }
        printf("\n");
    }
    printf("\n");
}

void addDot(int row, int column)
{
    grid[row][column] = 1;
}

void removeDot(int row, int column)
{
    grid[row][column] = 0;
}

void nextFrame()
{
    int newGrid[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS] = {0};

    for (int row = 0; row < NUMBER_OF_ROWS; ++row)
    {
        for (int column = 0; column < NUMBER_OF_COLUMNS; ++column)
        {
            int neighboors = 0;
            if (row > 0 && column > 0 && grid[row - 1][column - 1] == 1)
                neighboors++;
            if (row > 0 && grid[row - 1][column] == 1)
                neighboors++;
            if (row > 0 && column < 9 && grid[row - 1][column + 1] == 1)
                neighboors++;
            if (column < 9 && grid[row][column + 1] == 1)
                neighboors++;
            if (row < 9 && column < 9 && grid[row + 1][column + 1] == 1)
                neighboors++;
            if (row < 9 && grid[row + 1][column] == 1)
                neighboors++;
            if (row < 9 && column > 0 && grid[row + 1][column - 1] == 1)
                neighboors++;
            if (column > 0 && grid[row][column - 1] == 1)
                neighboors++;
            if (neighboors == 3 || (grid[row][column] == 1 && neighboors == 2))
                newGrid[row][column] = 1;
        }
    }

    for (int row = 0; row < NUMBER_OF_ROWS; row++)
        for (int column = 0; column < NUMBER_OF_COLUMNS; column++)
            grid[row][column] = newGrid[row][column];
}