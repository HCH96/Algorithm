#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int T, N, M, K, W, R, Q, S;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S1, S2;
    cin >> S1 >> S2;

    vector<vector<int>> dp(S1.size() + 1, vector<int>(S2.size() + 1, 0));

    for (int i = 1; i <= S1.size(); ++i)
    {
        for (int j = 1; j <= S2.size(); ++j)
        {
            int CurLCS = max(dp[i - 1][j], dp[i][j - 1]);

            if (S1[i-1] == S2[j-1])
            {
                CurLCS = max(CurLCS, dp[i - 1][j - 1] + 1);
            }

            dp[i][j] = CurLCS;
        }
    }

    int Row = S1.size();
    int Col = S2.size();

    int MaxLCS = dp[Row][Col];

    cout << MaxLCS << "\n";

    string Answer;

    while (MaxLCS > 0&& Row>0&& Col>0)
    {
        if (dp[Row][Col] == dp[Row][Col - 1])
        {
            --Col;
            continue;
        }

        if (dp[Row][Col] == dp[Row - 1][Col])
        {
            --Row;
            continue;
        }

        Answer.push_back(S1[Row-1]);
        --Row;
        --Col;
    }

    for (int i = Answer.size() - 1; i >= 0; --i)
    {
        cout << Answer[i];
    }

	return 0;
}