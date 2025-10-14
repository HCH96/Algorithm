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

    vector<long long> v(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long CurMin = LLONG_MAX;
    vector<long long> Answer(3);

    for (int i = 0; i < N - 2; ++i)
    {
        long long Sum = v[i];

        int Left = i + 1;
        int Right = N - 1;

        while (Left < Right)
        {
            long long CurSum = Sum + v[Left] + v[Right];

            if (abs(CurSum) < abs(CurMin))
            {
                CurMin = CurSum;
                Answer[0] = v[i];
                Answer[1] = v[Left];
                Answer[2] = v[Right];
            }

            if (CurSum < 0)
            {
                ++Left;
            }
            else
            {
                --Right;
            }
        }
    }

    cout << Answer[0] << " " << Answer[1] << " " << Answer[2];

    return 0;
}