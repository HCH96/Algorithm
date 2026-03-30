#include <iostream>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	vector<vector<long long>> PrefixSum(N + 1, vector<long long>(M+1, 0));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> PrefixSum[i + 1][j + 1];
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			PrefixSum[i][j] += PrefixSum[i - 1][j] + PrefixSum[i][j - 1] - PrefixSum[i - 1][j - 1];
		}
	}

	int K;
	cin >> K;

	for (int i = 0; i < K; ++i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;


		cout << PrefixSum[x2][y2] - PrefixSum[x1 - 1][y2] - PrefixSum[x2][y1 - 1] + PrefixSum[x1 - 1][y1 - 1] << endl;

	}


	return 0;
}
