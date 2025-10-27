#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int T, N, M, K, W, R, Q, S, G, P;

int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;

    if (N < 10)
    {
        cout << 0;
        return 0;
    }

    // 0000000000
    // 9876543210
    // [last][Mask] = Count
    vector<vector<long long>> dp(10, vector<long long>(1024, 0));

    for (int i = 1; i < 10; ++i)
    {
        int Mask = 0;
        Mask |= 1 << i;
        dp[i][Mask] = 1;
    }

    for (int i = 1; i < N; ++i)
    {
        vector<vector<long long>> Tmp(10, vector<long long>(1024, 0));

        for (int j = 0; j < 10; ++j)
        {
            for (int k = 0; k < 1024; ++k)
            {
                if (j - 1 >= 0)
                {
                    int Mask = k;
                    Mask |= 1 << (j - 1);

                    Tmp[j - 1][Mask] += dp[j][k];
                    Tmp[j - 1][Mask] %= 1000000000;

                }

                if (j + 1 < 10)
                {
                    int Mask = k;
                    Mask |= 1 << (j + 1);

                    Tmp[j + 1][Mask] += dp[j][k];
                    Tmp[j + 1][Mask] %= 1000000000;
                }
            }
        }

        dp = Tmp;
    }

    long long Answer = 0;

    for (int i = 0; i < 10; ++i)
    {
        Answer += dp[i][1023];
    }

    cout << Answer%1000000000;


    return 0;
}