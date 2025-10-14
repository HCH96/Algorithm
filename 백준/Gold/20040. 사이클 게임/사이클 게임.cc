#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int T, N, M, K, W, R, Q, S;

vector<int> Parent;


int Find(int Cur)
{
    if (Parent[Cur] == Cur)
        return Cur;

    return Parent[Cur] = Find(Parent[Cur]);
}

void Union(int First, int Second)
{
    int FirstParent = Find(First);
    int SecondParent = Find(Second);

    Parent[FirstParent] = SecondParent;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    vector<pair<int, int>> Edges;
    Parent.resize(N);

    for (int i = 0; i < N; ++i)
    {
        Parent[i] = i;
    }

    for (int i = 0; i < M; ++i)
    {
        int s, e;
        cin >> s >> e;
        Edges.push_back({ s,e });
    }

    int Answer = 0;

    for (int i = 0; i < Edges.size(); ++i)
    {
        int s = Find(Edges[i].first);
        int e = Find(Edges[i].second);

        if (s == e)
        {
            Answer = i+1;
            break;
        }

        Union(s, e);
    }

    cout << Answer;

	return 0;
}