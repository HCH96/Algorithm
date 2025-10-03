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

    cin >> N >> S;

    vector<int> v(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
    }

    int Answer = INT_MAX;
    int Sum = 0;

    int left = 0;
    
    for (int i = 0; i < N; ++i)
    {
        Sum += v[i];

        while (left <= i && Sum >= S)
        {
            Answer = min(Answer, i - left + 1);
            Sum -= v[left++];
        }
    }

    if (Answer == INT_MAX)
        Answer = 0;

    cout << Answer;

	return 0;
}