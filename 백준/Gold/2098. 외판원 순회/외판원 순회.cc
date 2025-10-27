#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int T, N, M, K, W, R, Q, S, G, P;

int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

struct cmp {

    bool operator()(const vector<int>& First, const vector<int>& Second)
    {
        return First[0] > Second[0];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    vector<vector<int>> Edge(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int Weight;
            cin >> Weight;
            Edge[i][j] = Weight;
        }
    }

    // 0000000000000000
    // {Dist, CurNode, Mask, StartNode}
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

    // [Node,Mask] = Dist
    vector<vector<int>> DistArr(N, vector<int>((1 << N), INT_MAX));

    DistArr[0][1] = 0;
    pq.push({ 0,0,1,0 });

    const int Finished = (1 << N) - 1;
    int Answer = INT_MAX;


    while (!pq.empty())
    {
        vector<int> Cur = pq.top();
        pq.pop();

        int Dist = Cur[0];
        int CurNode = Cur[1];
        int Mask = Cur[2];
        int StartNode = Cur[3];

        if (DistArr[CurNode][Mask] != Dist)
            continue;

        if (Mask == Finished && Edge[CurNode][StartNode] != 0)
        {
            Answer = min(Answer, Dist + Edge[CurNode][StartNode]);
            continue;
        }

        if (Mask == Finished) continue;

        for (int Next = 0; Next < N; ++Next)
        {
            if (Edge[CurNode][Next] == 0 || (Mask & (1 << Next)) != 0)
            {
                continue;
            }

            int NewMask = Mask | (1 << Next);
            int NewDist = Dist + Edge[CurNode][Next];

            if (Dist + Edge[CurNode][Next] < DistArr[Next][NewMask])
            {
                pq.push({ Dist + Edge[CurNode][Next], Next, NewMask, StartNode });
                DistArr[Next][NewMask] = Dist + Edge[CurNode][Next];
            }
        }
    }

    cout << Answer;


    return 0;
}