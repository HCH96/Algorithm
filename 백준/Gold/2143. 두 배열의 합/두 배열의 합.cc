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
    
    cin >> T;

    cin >> N;

    vector<long long> Arr1(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> Arr1[i];
    }

    cin >> M;
    vector<long long> Arr2(M);
    for (int i = 0; i < M; ++i)
    {
        cin >> Arr2[i];
    }

    vector<long long> Prefix1(N+1);
    Prefix1[0] = 0;
    for (int i = 1; i <= N; ++i)
    {
        Prefix1[i] = Prefix1[i - 1] + Arr1[i-1];
    }

    vector<long long> Prefix2(M + 1);
    Prefix2[0] = 0;
    for (int i = 1; i <= M; ++i)
    {
        Prefix2[i] = Prefix2[i - 1] + Arr2[i - 1];
    }

    unordered_map<long long, long long> um1;

    for (int i = N; i > 0; --i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            long long Sum = Prefix1[i] - Prefix1[j];
            ++um1[Sum];
        }
    }

    unordered_map<long long, long long> um2;

    for (int i = M; i > 0; --i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            long long Sum = Prefix2[i] - Prefix2[j];
            ++um2[Sum];
        }
    }
    long long Answer = 0;

    for (auto [Sum, Count] : um1)
    {
        long long Target = T - Sum;
        long long Count2 = um2[Target];
        
        Answer += Count * Count2;
    }

    cout << Answer;

	return 0;
}