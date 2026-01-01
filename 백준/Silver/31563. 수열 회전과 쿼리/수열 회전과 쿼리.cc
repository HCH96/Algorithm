#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <unordered_set>

using namespace std;

int N, Q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;

    vector<int> v(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
    }
    vector<long long> PrefixSum(N);
    PrefixSum[0] = v[0];

    for (int i = 1; i < N; ++i)
    {
        PrefixSum[i] = PrefixSum[i - 1] + v[i];
    }

    int Left = 0;

    for (int i = 0; i < Q; ++i)
    {
        int q;
        cin >> q;

        if (q == 1)
        {
            int k;
            cin >> k;

            Left = (Left - k + N) % N;
        }

        if (q == 2)
        {
            int k;
            cin >> k;

            Left = (Left + k + N) % N;
        }

        if (q == 3)
        {
            int Start, End;
            cin >> Start >> End;

            Start = (Left + Start - 1) % N;
            End = (Left + End - 1) % N;

            long long Sum = 0;

            if (Start <= End)
            {
                Sum = PrefixSum[End];
                if (Start > 0)
                    Sum -= PrefixSum[Start - 1];
            }
            else
            {
                Sum = PrefixSum[N - 1];
                if (Start > 0)
                    Sum -= PrefixSum[Start - 1];
                Sum += PrefixSum[End];
            }

            cout << Sum << "\n";
        }
    }


    return 0;
}
