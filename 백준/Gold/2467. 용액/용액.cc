#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int T, N, M, K, W;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
    }

    int left = 0;
    int right = N - 1;
    int MaxVal = INT_MAX;
    pair<int, int> Answer;

    while (left < right)
    {
        long long Sum = ((long long)v[left]) + v[right];

        if (abs(MaxVal) > abs(Sum))
        {
            MaxVal = Sum;
            Answer = { v[left] ,v[right] };
        }

        if (Sum > 0)
        {
            --right;
        }
        else
        {
            ++left;
        }
    }

    cout << Answer.first << " " << Answer.second;

	return 0;
}