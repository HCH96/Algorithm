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

    vector<long long> Edge(N - 1);
    vector<long long> v(N);

    for (int i = 0; i < N - 1; ++i)
    {
        cin >> Edge[i];
    }

    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
    }

    long long MinPrice = INT_MAX;
    long long Answer = 0;

    for (int i = 0; i < N - 1; ++i)
    {
        MinPrice = min(MinPrice, v[i]);
        Answer += MinPrice * Edge[i];
    }

    cout << Answer;

    return 0;
}