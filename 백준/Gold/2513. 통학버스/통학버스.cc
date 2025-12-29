#include <iostream>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int N, K, S, Answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K >> S;

    vector<vector<int>> Arr(N);

    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        Arr[i] = { a,b };
    }

    sort(Arr.begin(), Arr.end());

    int Carry = 0;

    for (int i = 0; i < N; ++i)
    {
        if (Arr[i][0] >= S)
            break;

        Carry += Arr[i][1];

        while (Carry > K)
        {
            Answer += 2 * (S - Arr[i][0]);
            Carry -= K;
        }
    }

    Carry = 0;
    for (int i = N - 1; i >= 0; --i)
    {
        if (Arr[i][0] <= S)
            break;

        Carry += Arr[i][1];

        while (Carry > K)
        {
            Answer += 2 * (Arr[i][0] - S);
            Carry -= K;
        }
    }
    
    if (Arr[0][0] < S)
    {
        Answer += 2 * (S - Arr[0][0]);
    }

    if (Arr[N - 1][0] > S)
    {
        Answer += 2 * (Arr[N - 1][0] - S);
    }

    cout << Answer;
    
    return 0;
}