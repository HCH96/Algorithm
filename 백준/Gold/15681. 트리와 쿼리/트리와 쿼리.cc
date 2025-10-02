#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int T, N, M, K, W, R, Q;


int GetSubTreeCount(int Prev, int CurNode, const vector<vector<int>>& Edge, vector<int>& SubTreeCount)
{
    int Sum = 1;

    for (auto Next : Edge[CurNode])
    {
        if (Prev == Next)
            continue;

        Sum += GetSubTreeCount(CurNode, Next, Edge,SubTreeCount);
    }

    return SubTreeCount[CurNode] = Sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> R >> Q;

    vector<vector<int>> Edge(N + 1);
    vector<int> SubTreeCount(N + 1, 0);

    for (int i = 0; i < N-1; ++i)
    {
        int s, e;
        cin >> s >> e;

        Edge[s].push_back(e);
        Edge[e].push_back(s);
    }


    GetSubTreeCount(0, R, Edge, SubTreeCount);

    for (int i = 0; i < Q; ++i)
    {
        int q;
        cin >> q;
        cout << SubTreeCount[q] << "\n";
    }


	return 0;
}