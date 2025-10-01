#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int T, N, M, K, W;

vector<int> Parent;
vector<int> Rank;

struct cmp
{
    bool operator()(const vector<int>& Left, const vector<int>& Right)
    {
        return Left[0] > Right[0];
    }
};

int Find(int CurNode)
{
    if (Parent[CurNode] == CurNode)
        return CurNode;

    return Parent[CurNode] = Find(Parent[CurNode]);
}

void Union(int u, int v)
{
    u = Find(u);
    v = Find(v);

    if (Rank[u] < Rank[v])
        swap(u, v);

    Parent[v] = u;

    if (Rank[u] == Rank[v])
        ++Rank[u];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    Parent.resize(N + 1);
    for (int i = 0; i < N + 1; ++i)
    {
        Parent[i] = i;
    }

    Rank.resize(N + 1, 0);


    priority_queue<vector<int>,vector<vector<int>>, cmp> pq;

    for (int i = 0; i < M; ++i)
    {
        int s, e, w;
        cin >> s >> e >> w;
        pq.push({ w,s,e });
    }

    int Answer = 0;
    int MaxEdge = 0;

    while (!pq.empty())
    {
        int Weight = pq.top()[0];
        int u = pq.top()[1];
        int v = pq.top()[2];
        pq.pop();

        if (Find(u) != Find(v))
        {
            Union(u, v);
            Answer += Weight;
            MaxEdge = max(MaxEdge, Weight);
        }
    }

    cout << Answer - MaxEdge;

	return 0;
}