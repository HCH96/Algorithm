#include <iostream>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int N, M;


string VecToString(vector<int>& v)
{
    string s;
    
    for (auto ix : v)
    {
        s += to_string(ix);
        s += ' ';
    }

    return s;
}

void StringToVec(const string& s, vector<int>& v)
{
    v.clear();

    stringstream ss(s);
    int x;

    while (ss >> x)
    {
        v.push_back(x);
    }
}

bool Check(const vector<int>& v)
{
    if (v.size() == 0)
    {
        return true;
    }

    int Prev = v[0];

    for (int i = 1; i < v.size(); ++i)
    {
        if (Prev > v[i])
            return false;

        Prev = v[i];
    }

    return true;
}

struct cmp
{
    bool operator()(const pair<int, vector<int>>& Left, const pair<int, vector<int>>& Right)
    {
        return Left.first > Right.first;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Answer = INT_MAX;

    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
    }

    vector<int> Sorted = v;
    sort(Sorted.begin(), Sorted.end());

    cin >> M;

    vector<vector<int>> Operation;
    for (int i = 0; i < M; ++i)
    {
        int l, r, c;
        cin >> l >> r >> c;

        Operation.push_back({ l-1,r-1,c });
    }

    priority_queue < pair<int, vector<int>>, vector<pair<int, vector<int>>>, cmp> pq;

    map<vector<int>, int> Dist;
    Dist[v] = 0;
    pq.push({ 0, v });

    while (!pq.empty())
    {
        vector<int> CurVec = pq.top().second;
        int CurDist = pq.top().first;
        pq.pop();

        if (Dist[CurVec] < CurDist)
            continue;

        if (CurVec == Sorted)
        {
            Answer = min(Answer, CurDist);
            continue;
        }

        for (int i = 0; i < M; ++i)
        {
            int Left, Right, Cost;
            Left = Operation[i][0];
            Right = Operation[i][1];
            Cost = Operation[i][2];

            vector<int> NewVec = CurVec;
            swap(NewVec[Left], NewVec[Right]);
            int NewDist = CurDist + Cost;


            if (Dist.find(NewVec) == Dist.end())
            {
                Dist[NewVec] = NewDist;
                pq.push({ NewDist,NewVec });
                continue;
            }

            if (Dist[NewVec] > NewDist)
            {
                Dist[NewVec] = NewDist;
                pq.push({ NewDist,NewVec });
            }
        }
    }

    if (Answer == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << Answer;
    }

    return 0;
}