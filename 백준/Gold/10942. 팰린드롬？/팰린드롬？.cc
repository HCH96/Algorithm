#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int T, N, M, K, W, R, Q, S;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
    }

    vector<vector<int>> dp(N, vector<int>(N, 0));
    
    for (int i = 0; i < N; ++i)
    {
        int left = i;
        int right = i;

        while (left >= 0 && right < N && v[left] == v[right])
        {
            dp[left][right] = 1;
            --left;
            ++right;
        }
    }

    for (int i = 0; i < N - 1; ++i)
    {
        int left = i;
        int right = i + 1;

        while (left >= 0 && right < N && v[left] == v[right])
        {
            dp[left][right] = 1;
            --left;
            ++right;
        }
    }

    cin >> M;

    for (int i = 0; i < M; ++i)
    {
        int s, e;
        cin >> s >> e;
        cout << dp[s-1][e-1] << "\n";
    }

	return 0;
}