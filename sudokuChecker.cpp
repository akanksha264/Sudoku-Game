/*
SUDOKU CHECKER
BY - AKANKSHA KEJRIWAL
DATE - 15th JUNE 2022
*/

#include <iostream>
#include <vector>
using namespace std;

class Sudoku
{
    vector<vector<int> > board;
    int n;

    bool isValid(int , int , int);

    public:
        Sudoku(){
            n=9;
            vector<int> row(n,0);
            for(int i=0 ; i<n ; i++)
                board.push_back(row);
        }

        void input();
        bool check();
        void display();
};

void Sudoku::input()
{
    cout << "Enter a valid sudoku :-\n";
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<n ; j++)
            cin >> board[i][j];
}

bool Sudoku::check()
{
    //Checking if every number is in a valid position
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<n ; j++)
        {
        	int val=board[i][j];
        	board[i][j]=0;
            if(!isValid(i,j,val))
                return false;
            board[i][j]=val;
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

main()
{
    Sudoku s;
    s.input();
    if(s.check())
        cout << "Valid";
    else    
        cout << "Not Valid";
    return 0;
}

/*
4 3 5 2 6 9 7 8 1
6 8 2 5 7 1 4 9 3
1 9 7 8 3 4 5 6 2
8 2 6 1 9 5 3 4 7
3 7 4 6 8 2 9 1 5
9 5 1 7 4 3 6 2 8
5 1 9 3 2 6 8 7 4
2 4 8 9 5 7 1 3 6
7 6 3 4 1 8 2 5 9
*/
