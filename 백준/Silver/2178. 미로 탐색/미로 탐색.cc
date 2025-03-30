#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    int **arr = new int *[n + 2];
    for (int j = 0; j < n + 2; j++)
    {
        arr[j] = new int[m + 2];
    }

    for (int j = 0; j < n + 2; j++)
    {
        for (int k = 0; k < m + 2; k++)
        {
            arr[j][k] = 0;
        }
    }

    for (int j = 1; j < n + 1; j++)
    {
        string s;
        cin >> s;
        for (int k = 1; k < m + 1; k++)
        {
            arr[j][k] = s[k - 1] - '0';
        }
    }

    queue<tuple<int, int, int>> q;
    arr[1][1] = 0;
    q.push(make_tuple(1, 1, 1));
    int ans;
    while (!q.empty())
    {
        tuple<int, int, int> cur = q.front();
        q.pop();
        int row, col, cnt;
        row = get<0>(cur);
        col = get<1>(cur);
        cnt = get<2>(cur);

        if(row ==n && col == m)
        {
            ans = cnt;
        }

        //상
        if (arr[row - 1][col] == 1)
        {
            arr[row - 1][col] = 0;
            q.push(make_tuple(row - 1, col, cnt + 1));
        }
        //하
        if (arr[row + 1][col] == 1)
        {
            arr[row + 1][col] = 0;
            q.push(make_tuple(row + 1, col, cnt + 1));
        }
        //좌
        if (arr[row][col - 1] == 1)
        {
            arr[row][col - 1] = 0;
            q.push(make_tuple(row, col - 1, cnt + 1));
        }
        //우
        if (arr[row][col + 1] == 1)
        {
            arr[row][col + 1] = 0;
            q.push(make_tuple(row, col + 1, cnt + 1));
        }
    }

    cout << ans << "\n";
}