#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool isValid(int row, int col, const vector<string> &current)
{
    int n = current.size();

    for (int i = 0; i < n; i++)
    {
        if (current[i][col] == 'Q' || current[row][i] == 'Q')
            return false;
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (current[i][j] == 'Q')
        {
            return false;
        }
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (current[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}


void backtrack(int row, vector<string> &current, vector<vector<string> > &result)
{
    if (row == current.size())
    {
        result.push_back(current);
        return;
    }

    for (int col = 0; col < current[row].size(); col++)
    {
        if (isValid(row, col, current))
        {
            current[row][col] = 'Q';
            backtrack(row + 1, current, result);
            current[row][col] = '.';
        }
    }
}

vector<vector<string> > solveNQueens(int n)
{
    vector<vector<string> > result{};
    vector<string> current(n, string(n, '.'));

    backtrack(0, current, result);

    return result;
}

void print(const vector<vector<string> > &result)
{
    for (const auto &i: result)
    {
        for (const auto &j: i)
        {
            cout << j << endl;
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;

    vector<int> solutions{};

    const vector<vector<string> > result = solveNQueens(n);

    print(result);

    // for (int i = 0; i < solutions.size(); i++)
    //     cout << solutions[i] << endl;
    cout << "number of solutions: " << result.size() << endl;

    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();
    return 0;
}
