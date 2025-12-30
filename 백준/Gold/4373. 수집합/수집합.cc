#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <unordered_set>

using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        cin >> N;
        if (N == 0)
            break;

        int Answer = -1;
        vector<long long> v(N);

        for(int i=0; i<N; ++i)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        unordered_map<long long,pair<int,int>> um;
        for (int i = 0; i < N; ++i)
        {
            for (int j = i + 1; j < N; ++j)
            {
                um[v[i] + v[j]] = { i,j };
            }
        } 

        for (int i = N - 1; i >= 1; --i)
        {
            long long d = v[i];

            for (int j = i - 1; j >= 0; --j)
            {
                long long Target = d - v[j];

                if (um.find(Target) != um.end())
                {
                    auto [Left, Right] = um[Target];

                    if (Left != i && Left != j && Right != i && Right != j)
                    {
                        Answer = d;
                        break;
                    }
                }
            }
            if (Answer != -1)
                break;
        }

        if (Answer == -1)
        {
            cout << "no solution\n";
        }
        else
        {
            cout << Answer << endl;
        }

    }
    
    return 0;
}
