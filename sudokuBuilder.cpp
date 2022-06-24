/*
FILLED RANDOM SUDOKU BUILDER
BY - AKANKSHA KEJRIWAL
DATE - 16th JUNE 2022
*/

#include <iostream>
#include <vector>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Sudoku
{
    vector<vector<int>> board;
    int n;

    // Private member functions
    bool generate();
    bool solve(int, int);
    bool isValid(int, int, int);

public:
    Sudoku()
    {
        n = 9;
        vector<int> row(n, 0);
        for (int i = 0; i < n; i++)
            board.push_back(row);

        //Set seed for random number generator
        srand(time(0));

        //Generate a board until a possible configuration is found
        bool isGenerated=false;
        do
        {
            isGenerated=generate();
        } while (!isGenerated);
    }

    void display();
};

bool Sudoku::generate()
{
    //Filling diagonal 3x3 boxes with random number from 1 to 9
    for(int i=0 ; i<n ; i+=3)
    {
        bool used[9]={0}; //Keep a record of filled numbers

        for(int x=0 ; x<3 ; x++)
        {
            for(int y=0 ; y<3 ; y++)
            {
                int num;
                do
                {
                    //Generate a random number
                    num=rand()%9 + 1;
                } while (used[num-1]); //Loop until an unused number is not found
                
                //Mark number as used
                used[num-1]=1;
                //Fill number in cell
                board[x+i][y+i]=num;
            }
        }
    }

    //Now solve the sudoku and check if a solution is possible
    return solve(0,0);
}

bool Sudoku::solve(int r, int c)
{
    // If last row is complete sudoku is solved
    if (r >= 9)
        return true;

    // If column end is reached, change row
    if (c >= 9)
        return solve(r + 1, 0);

    // If cell is not empty, go to next cell
    if (board[r][c] != 0)
        return solve(r, c + 1);

    // Fill the cell with a number
    for (int i = 1; i <= 9; i++)
    {
        if (isValid(r, c, i))
        {
            board[r][c] = i;
            if (solve(r, c + 1))
                return true;
            board[r][c] = 0;
        }
    }

    return false;
}

bool Sudoku::isValid(int row, int col, int val)
{
    // Checking the row
    for (int i = 0; i < n; i++)
        if (board[row][i] == val)
            return false;

    // Checking the column
    for (int i = 0; i < n; i++)
        if (board[i][col] == val)
            return false;

    // Checking the 3x3 box
    int i = (row / 3) * 3;
    int j = (col / 3) * 3;
    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            if (board[i + x][j + y] == val)
                return false;

    return true;
}

void Sudoku::display()
{
    cout << "\n\nRandom Sudoku :-\n";
    cout << "---------------------\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}

main()
{
    Sudoku s;
    s.display();

    return 0;
}
