#include<iostream>
#include<vector>
using namespace std;

int n;
vector<vector<int>> board;

bool isSafe(int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        if(board[i][col] == 1) return false;
        if(col - (row-i) >= 0 && board[i][col-(row-i)] == 1) return false;
        if(col + (row-i) < n && board[i][col+(row-i)] == 1) return false;
    }
    return true;
}

bool solve(int row)
{
    if(row ==n) return true;
    for(int col = 0 ; col < n ; col++)
    {
        if(isSafe(row,col))
        {
            board[row][col] = 1;
            if(solve(row+1)) return true;
            board[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    cout<<"Enter number of queens: ";
    cin>>n;
    board.assign(n,vector<int>(n,0));

    int firstCol;
    cout<<"Enter column for first queen(0 to "<<n-1<<"): ";
    cin>>firstCol;
    board[0][firstCol] = 1;

    if(solve(1))
    {
        cout<<"\nFirst N-queens Matrix:\n";
        for(int i = 0; i < n ; i++)
        {
            for(int j = 0; j < n ; j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"No solution found";
    }

    return 0;
}