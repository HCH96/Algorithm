#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C, N, M;

int ans;


void Solution(int Count, int idx, const vector<pair<int, int>>& Friend, vector<bool>& Selected)
{
    if (Count == N)
    {
        ++ans;
        return;
    }

    for (int i = idx; i < Friend.size(); ++i)
    {
        int First = Friend[i].first;
        int Second = Friend[i].second;

        if (Selected[First] == false && Selected[Second] == false)
        {
            Selected[First] = true;
            Selected[Second] = true;

            Solution(Count + 2, i + 1, Friend, Selected);

            Selected[First] = false;
            Selected[Second] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> C;

    while (C--)
    {
        ans = 0;

        cin >> N >> M;

        vector<pair<int, int>> Friend(M);
        vector<bool> Selected(N, false);

        for (int i = 0; i < M; ++i)
        {
            int First, Second;
            cin >> First >> Second;

            Friend[i] = { First,Second };
        }

        Solution(0, 0, Friend, Selected);

        cout << ans << endl;
    }

    return 0;
}
