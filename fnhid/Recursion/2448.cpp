#include <iostream>
#include <vector>

using namespace std;

//3*2^10


vector<vector<char>> board(3072, vector<char>(3072*2-1, ' '));

void paint(int r, int c, int n)
{
    if (n == 3)
    {
        board[r][c] = '*';
        board[r+1][c-1] = '*';
        board[r+1][c+1] = '*';
        board[r+2][c+1] = '*';
        board[r+2][c+2] = '*';
        board[r+2][c] = '*';
        board[r+2][c-1] = '*';
        board[r+2][c-2] = '*';
    } else
    {
        paint(r, c,n/2);
        paint(r+n/2, c-n/2,n/2);
        paint(r+n/2, c+n/2,n/2);
    }
}

int main()
{

    int n;
    cin >> n;


    paint(0,n-1,n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }

}

