#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <unordered_set>

using namespace std;

int N, K, T;

vector<vector<long long>> dp;
vector<vector<int>> cost;
vector<vector<int>> edge;

long long Sol(int Cur, int IsBlack)
{
	if (edge[Cur].size() == 0)
		return cost[Cur][IsBlack];

	if (dp[IsBlack][Cur] != -1)
		return dp[IsBlack][Cur];

	long long CurCost = cost[Cur][IsBlack];

	for (auto Child : edge[Cur])
	{
		long long ChildCost = Sol(Child, 0);

		if (!IsBlack)
		{
			ChildCost = min(ChildCost, Sol(Child, 1));
		}

		CurCost += ChildCost;
	}

	dp[IsBlack][Cur] = CurCost;

	return CurCost;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	dp.resize(2, vector<long long>(N, -1));
	edge.resize(N, vector<int>());

	for (int i = 0; i < N-1; ++i)
	{
		int p, c;
		cin >> p >> c;
		edge[p].push_back(c);
	}

	for (int i = 0; i < N; ++i)
	{
		int w, b;
		cin >> w >> b;
		
		cost.push_back({ w,b });
	}

	long long Answer = LLONG_MAX;

	for (int i = 0; i < 2; ++i)
	{
		Answer = min(Answer, Sol(0,i));
	}

	cout << Answer;

	return 0;
}
