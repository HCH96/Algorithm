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

    const int Finished = (1 << N) - 1;
    int Answer = INT_MAX;

    // 0000000000000000

    // [Node][Mask]
    vector<vector<int>> dp(N, vector<int>((1 << N), INT_MAX));

    // 시작 0번 노드
    dp[0][1] = 0;

    
    for (int mask = 0; mask <= Finished; ++mask)
    {
        for (int node = 0; node < N; ++node)
        {
            if (dp[node][mask] == INT_MAX)
                continue;

            for (int next = 0; next < N; ++next)
            {
                if(mask & (1 << next) || Edge[node][next] == 0)
					continue;

                int nextMask = mask | (1 << next);
				dp[next][nextMask] = min(dp[next][nextMask], dp[node][mask] + Edge[node][next]);
            }
        }
    }
    
    for (int i = 0; i < N; ++i)
	{
		if (dp[i][Finished] ==INT_MAX || Edge[i][0] == 0)
			continue;

		Answer = min(Answer, dp[i][Finished] + Edge[i][0]);
	}

    cout << Answer;

    return 0;
}