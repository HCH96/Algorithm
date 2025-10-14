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

    vector<bool> Prime(N+1,true);
    Prime[0] = false;
    Prime[1] = false;

    for (int i = 2; i*i <= N; ++i)
    {
        if (Prime[i] == false)
            continue;

        for (int j = i * i; j <= N; j += i)
        {
            Prime[j] = false;
        }
    }

    vector<int> v;

    for (int i = 0; i < Prime.size(); ++i)
    {
        if (Prime[i])
        {
            v.push_back(i);
        }
    }


    int left = 0;
    long long Sum = 0;
    int Answer = 0;

    for (int i = 0; i < v.size(); ++i)
    {
        Sum += v[i];

        if (Sum >= N)
        {
            while (Sum > N)
            {
                Sum -= v[left++];
            }

            if (Sum == N)
                ++Answer;
        }
    }

    cout << Answer;

	return 0;
}