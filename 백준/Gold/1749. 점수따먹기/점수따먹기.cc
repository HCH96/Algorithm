#include <iostream>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int N, M;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	vector<vector<int>> v(N + 1, vector<int>(M + 1));
	for (int i = 1; i < N+1; ++i)
	{
		for (int j = 1; j < M+1; ++j)
		{
			cin >> v[i][j];
		}
	}

	vector<vector<int>> PrefixSum(N + 1, vector<int>(M + 1));

	for (int i = 1; i < N + 1; ++i)
	{
		for (int j = 1; j < M + 1; ++j)
		{
			PrefixSum[i][j] = PrefixSum[i - 1][j] + PrefixSum[i][j - 1] - PrefixSum[i - 1][j - 1] + v[i][j];
		}
	}


	int Answer = INT_MIN;

	for (int i = 1; i < N + 1; ++i)
	{
		for (int j = 1; j < M + 1; ++j)
		{
			for (int k = 0; k < i; ++k)
			{
				for (int l = 0; l < j; ++l)
				{

					Answer = max(Answer, PrefixSum[i][j] - PrefixSum[i][l] - PrefixSum[k][j] + PrefixSum[k][l]);

				}
			}

		}
	}

	
	cout << Answer;


	return 0;
}
