#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

bool isValid(int num, int row, int col, vector<vector<int>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
            return false;
        if (board[row][i] == num)
            return false;
    }

    int rowBorder = row / 3;
    int colBorder = col / 3;

    for (int i = rowBorder * 3; i < (rowBorder + 1) * 3; i++)
        for (int j = colBorder * 3; j < (colBorder + 1) * 3; j++)
            if (board[i][j] == num)
                return false;

    return true;
}


bool backtrack(int row, int col, vector<vector<int> > &board)
{
    if (row == 8 && col == 9)
        return true;

    if (col == 9)
    {
        row++;
        col = 0;
    }

    if (board[row][col] != 0)
    {
        return backtrack(row, col + 1, board);
    }

    for (int i = 1; i <= 9; i++)
    {
        if (isValid(i, row, col, board))
        {
            board[row][col] = i;
            if (backtrack(row, col + 1, board))
                return true;
        }

        board[row][col] = 0;
    }

    return false;
}


void solveSudoku(vector<vector<int>> &board)
{
    backtrack(0, 0, board);
}

void inputBoard(vector<vector<int> > &board)
{
    cout << "Enter your board, one row at a time (9 numbers separated by spaces):" << endl;
    for (int i = 0; i < 9; i++)
    {
        string line;
        getline(cin, line); // Read the entire row as a line
        stringstream ss(line);

        for (int j = 0; j < 9; j++)
        {
            ss >> board[i][j];
        }
    }
}

void print(const vector<vector<int>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

}

int main()
{
    //initialize the board
    vector<vector<int>> board(9,vector<int>(9,0));

    //input the board by the user
    inputBoard(board);

    //solves the board using backtrack method
    solveSudoku(board);

    cout << "\nThe solution is:\n" << endl;
    print(board);

    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}
