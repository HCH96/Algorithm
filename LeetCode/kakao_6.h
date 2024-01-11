#pragma once

#include <string>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

void mark(set<pair<int, int>> s, vector<string>& board, int& answer)
{
    set<pair<int, int>>::iterator iter = s.begin();

    while (iter != s.end())
    {
        board[iter->first][iter->second] = 'X';
        ++answer;
        ++iter;
    }
}

void drop(int m, int n, vector<string>& board)
{
    for (int i = 1; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] == 'X')
            {
                for (int k = i; k > 0; --k)
                {
                    swap(board[k][j], board[k - 1][j]);
                }
            }
        }
    }
}


void sol(int m, int n, vector<string>& board, int& answer)
{
    set<pair<int, int>> s;

    for (int i = 0; i < m - 1; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
        {
            char Cur = board[i][j];
            if ('X' != Cur && board[i + 1][j] == Cur && board[i][j + 1] == Cur && board[i + 1][j + 1] == Cur)
            {
                s.insert({ i,j });
                s.insert({ i + 1,j });
                s.insert({ i,j + 1 });
                s.insert({ i + 1,j + 1 });
            }
        }
    }

    mark(s, board, answer);
    drop(m, n, board);
    if (s.size() != 0)
    {
        sol(m, n, board, answer);
    }
}



int solution(int m, int n, vector<string> board) {
    int answer = 0;

    sol(m, n, board, answer);

    return answer;
}