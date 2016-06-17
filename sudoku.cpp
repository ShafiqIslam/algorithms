#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define UNASSIGNED 0
#define N 9

/* Searches the grid to find an entry that is still unassigned. */
bool FindUnassignedLocation(int grid[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}

/* Returns whether any assigned entry n the specified row matches
   the given number. */
bool UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

/* Returns whether any assigned entry in the specified column matches
   the given number. */
bool UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

/* Returns whether any assigned entry within the specified 3x3 box matches
   the given number. */
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}

bool isSafe(int grid[N][N], int row, int col, int num)
{
    return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row % 3 , col - col % 3, num);
}

bool SolveSudoku(int grid[N][N])
{
    int row, col;
    if (!FindUnassignedLocation(grid, row, col))
       return true;
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (SolveSudoku(grid))
                return true;
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}

void verticalLines()
{
    for(int col = 0; col < N; col++) {
        if(col==0)
            cout<<"|";

        cout<<"  ";

        if(col==N-1)
            cout<<" |";
        else if( (col+1) % 3 == 0 )
            cout<<" |";
    }
}

void horizontalLine(bool is_last)
{
    for(int col = 0; col < N; col++) {
        if(col==0)
            cout<<"---";
        else if(col==N-1)
            cout<<"-";
        else
            cout<<"---";
    }

    cout<<endl;

    if(!is_last) {
        verticalLines();
    }

    cout<<endl;
}

void printGrid(int grid[N][N])
{
    int row, col;
    horizontalLine(false);

    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if(col==0)
                cout<<"|";

            cout<<" ";
            if(grid[row][col]) {
                cout<<grid[row][col];
            } else {
                cout<<" ";
            }

            if(col==N-1)
                cout<<" |";
            else if( (col+1) % 3 == 0 )
                cout<<" |";
        }

        cout<<endl;
        verticalLines();
        cout<<endl;

        if(row==N-1)
            horizontalLine(true);
        else if( (row+1) % 3 == 0 )
            horizontalLine(false);
    }
}

int main()
{
    int grid[N][N] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    cout<<"Main Problem:\n-------------\n";
    printGrid(grid);

    cout<<"Solved:\n-------\n";
    if (SolveSudoku(grid) == true)
          printGrid(grid);
    else
        cout<<"No solution exists. Sorry :("<<endl;

    cout<<endl;
    return 0;
}
