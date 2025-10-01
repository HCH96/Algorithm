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

    vector<int> v;
    unordered_map<int, int> um;
    for (int i = 0; i < N; ++i)
    {
        int k;
        cin >> k;
        v.push_back(k);
        um[k] = 0;
    }

    for (auto p : um)
    {
        int CurNumber = p.first;

        int Target = CurNumber * 2;

        while (Target <= 1000000)
        {
            if (um.find(Target) != um.end())
            {
                ++um[CurNumber];
                --um[Target];
            }
            Target += CurNumber;
        }
    }

    for (int i = 0; i < v.size(); ++i)
    {
        cout << um[v[i]] << " ";
    }

	return 0;
}