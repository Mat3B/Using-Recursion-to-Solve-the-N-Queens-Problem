/*
 * Name: Mathew Breland
 * Date Submitted:
 * Lab Section: 001
 * Assignment Name: Lab9 - N Queens 
 */

#include <iostream>
using namespace std;

const int MAX = 100;

bool isSafe(int board[][MAX], int row, int col, int n)
{
    // there are no algorithms to check the space above or the space below due to the lack of placing queens yet

    for (int i = 0; i < col; i++)       // Check if there is a queen in the same row

       if (board[row][i])

            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)      // Check if there is a queen in the upper diagonal

        if (board[i][j])

            return false;

    for (int i = row, j = col; i < n && j >= 0; i++, j--)       // Check if there is a queen in the lower diagonal

        if (board[i][j])

            return false;

    
    return true;    // if everything is satisfied  then we return true
}

void solveNQueens(int board[][MAX], int col, int n, int& count)
{
    // Base case: If all queens are placed, increment the count
    if (col == n)
    {
        count++;
        return;
    }

    // Recursive case: Try placing the queen in each row of the current column
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, i, col, n))
        {
            board[i][col] = 1;   // Place the queen on this cell

            solveNQueens(board, col + 1, n, count);  // Recursively place the rest of the queens

            board[i][col] = 0;   // Backtrack if no solution is found

        }
    }
}

// Function uses '40008' bytes of stack: exceeds limit. idk why but it still works
int nQueens(int n)
{
    int board[MAX][MAX] = { 0 };

    // Call the recursive helper function
    int count = 0;
    solveNQueens(board, 0, n, count);

    return count;
}


