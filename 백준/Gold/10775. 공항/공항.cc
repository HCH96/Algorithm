#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int T, N, M, K, W, R, Q, S, G, P;

vector<int> Parent;

int Find(int Cur)
{
    if (Parent[Cur] == Cur)
        return Cur;

    return Parent[Cur] = Find(Parent[Cur]);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> G >> P;

    Parent.resize(G + 1);

    for (int i = 0; i < G+1; ++i)
    {
        Parent[i] = i;
    }

    int Answer = P;

    for (int i = 0; i < P; ++i)
    {
        int t;
        cin >> t;

        int Gate = Find(t);

        if (Gate <= 0)
        {
            Answer = i;
            break;
        }

        Parent[Gate] = Find(Gate - 1);

    }

    cout << Answer;

    return 0;
}