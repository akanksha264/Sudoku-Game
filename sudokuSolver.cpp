/*
SUDOKU SOLVER
BY - AKANKSHA KEJRIWAL
DATE - 16th JUNE 2022
*/

#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

class Sudoku
{
    vector< vector<int> > board;
    int n;
    bool isPossible;
    
    //Private member functions
    bool solve(int , int);
    bool isValid(int , int , int);

    public:
        Sudoku(){
            n=9;
            vector<int> row(n,0);
            for(int i=0 ; i<n ; i++)
                board.push_back(row);
        }

        void input();        
        void display();        
};

void Sudoku::input()
{
    cout << "Enter a valid incomplete sudoku (Enter \'0\' for blanks):-\n";
    cout << "------------------------------------------------------------\n";
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<n ; j++)
            cin >> board[i][j];

    isPossible=solve(0,0);
}

bool Sudoku::solve(int r , int c)
{
    //If last row is complete sudoku is solved
    if(r>=9)
        return true;
    
    //If column end is reached, change row
    if(c>=9)
        return solve(r+1 , 0);
    
    //If cell is not empty, go to next cell
    if(board[r][c]!=0)
        return solve(r , c+1);

    //Fill the cell with a number
    for(int i=1 ; i<=9 ; i++)
    {        
        if(isValid(r,c,i))
        {
            board[r][c]=i;
            if(solve(r , c+1))
                return true;
            board[r][c]=0;
        }       
    }
}

bool Sudoku::isValid(int row , int col , int val)
{
    //Checking the row
    for(int i=col+1 ; i<n ; i++)
        if(board[row][i]==val)
            return false;

    //Checking the column
    for(int i=row+1 ; i<n ; i++)
        if(board[i][col]==val)
            return false;

    //Checking the 3x3 box
    int i=(row/3)*3;
    int j=(col/3)*3;
    for(int x=0 ; x<3 ; x++)
        for(int y=0 ; y<3 ; y++)
            if(board[i+x][j+y]==val)
                return false;

    return true;
}

void Sudoku::display()
{
    if(!isPossible)
        cout<< "Invalid Sudoku!!";
        
    else
    {
        cout << "\n\nSolved Sudoku :-\n";
        cout << "---------------------\n";
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
                cout << board[i][j] << " ";
            cout << "\n";
        }
    }
}

main()
{
    Sudoku s;

    s.input();
    s.display();

    return 0;
}

/*
0 0 0 2 6 0 7 0 1
6 8 0 0 7 0 0 9 0
1 9 0 0 0 4 5 0 0
8 2 0 1 0 0 0 4 0
0 0 4 6 0 2 9 0 0
0 5 0 0 0 3 0 2 8
0 0 9 3 0 0 0 7 4
0 4 0 0 5 0 0 3 6
7 0 3 0 1 8 0 0 0
*/
