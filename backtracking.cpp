#include <iostream>
#include <cstring>
using namespace std;
#define N 5

int solution[N][N];
int letter_counter = 1;

bool search(char matrix[N][N], string word, int row, int col, int index) {

    // check if current cell not already used or character in it is not not
    if (solution[row][col] != 0 || word[index] != matrix[row][col]) {
        return false;
    }

    if (index == word.length() - 1) {
        // word is found, return true
        solution[row][col] = letter_counter;
        return true;
    }

    solution[row][col] = letter_counter;
    letter_counter++;

    if (row + 1 < N && search(matrix, word, row + 1, col, index + 1)) { // go  down
        return true;
    }
    if (row - 1 >= 0 && search(matrix, word, row - 1, col, index + 1)) { // go up
        return true;
    }
    if (col + 1 < N && search(matrix, word, row, col + 1, index + 1)) { // go right
        return true;
    }
    if (col - 1 >= 0 && search(matrix, word, row, col - 1, index + 1)) { // go left
        return true;
    }
    if (row - 1 >= 0 && col + 1 < N && search(matrix, word, row - 1, col + 1, index + 1)) {
        // go diagonally up right
        return true;
    }
    if (row - 1 >= 0 && col - 1 >= 0 && search(matrix, word, row - 1, col - 1, index + 1)) {
        // go diagonally up left
        return true;
    }
    if (row + 1 < N && col - 1 >= 0 && search(matrix, word, row + 1, col - 1, index + 1)) {
        // go diagonally down left
        return true;
    }
    if (row + 1 < N && col + 1 < N && search(matrix, word, row + 1, col + 1, index + 1)) {
        // go diagonally down right
        return true;
    }

    // if none of the option works out, BACKTRACK and return false
    solution[row][col] = 0;
    letter_counter--;
    return false;
}

bool searchWord(char matrix[N][N], string word)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (search(matrix, word, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}

void printSolution()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << " " << solution[i][j];
        }
        cout<<endl;
    }
}

int main()
{
    char matrix[N][N] = {
        { 't', 'z', 'x', 'c', 'd' },
        { 'a', 'h', 'n', 'z', 'x' },
        { 'h', 'w', 'o', 'i', 'o' },
        { 'o', 'r', 'n', 'r', 'n' },
        { 'a', 'b', 'r', 'i', 'n' }
    };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            solution[i][j] = 0;
        }
    }

    if ( searchWord(matrix, "horizon") ) {
        printSolution();
    } else {
        cout << "NO PATH FOUND";
    }

    cout<<endl;
    return 0;
}



/*
            Theories
        ===============

Algorithm: Basic Backtracking

Problem: Given a 2D matrix of characters. Check whether the word exist in the matrix or not.
If it exists then print its path. All movements are allowed (right, left, up, down and diagonally).

1. Create a solution matrix of the same structure as Matrix.
2. Try each cell a starting point.
3. Check current cell is not already used and character in it matches with the character in the word at index (starts will 0).
4. Check if index = length of the word, means we have found the word. return true and print the solution matrix.
5. If above criteria matches, mark that cell with a number. Whenever any cell matches with the criteria,
   put a number corresponding to it in solution matrix. (start with 0 and keep incrementing it,
   it will show us the path for the word).
        a. Now try to solve rest of the problem recursively by making index +1.
           Check all 8 directions ( up, down, left right, diagonally up-left, diagonally up-right, diagonally down-left,
           diagonally down-right). Check the boundary conditions as well
        b. If none of the 8 recursive calls return true, BACKTRACK and undo the changes ( put 0 to corresponding cell in solution matrix)
           and return false.
6. Choose different starting point.
7. If all the starting points tried and solution not found, return false

*/
