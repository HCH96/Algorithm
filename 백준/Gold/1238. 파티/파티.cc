#include <bits/stdc++.h>

using namespace std;

int N, M, K, V, X;

void Sol(const vector<vector<pair<int, int>>>& edge, vector<int>& m, int Start)
{
	m[Start] = 0;

	priority_queue <pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,Start });

	while (!pq.empty())
	{
		int CurCost = pq.top().first;
		int CurNode = pq.top().second;
		pq.pop();

		for (int i = 0; i < edge[CurNode].size(); ++i)
		{
			int NextNode = edge[CurNode][i].first;
			int NextCost = edge[CurNode][i].second;

			if (CurCost + NextCost < m[NextNode])
			{
				m[NextNode] = CurCost + NextCost;
				pq.push({ CurCost + NextCost, NextNode });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> X;

	vector<vector<pair<int, int>>> edge(N);
	vector<vector<int>> m(N, vector<int>(N, INT_MAX));

	for (int i = 0; i < M; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;

		--start;
		--end;

		edge[start].push_back({ end,cost });
	}


	for (int i = 0; i < N; ++i)
	{
		Sol(edge, m[i], i);
	}
	
	int ans = 0;

	int MaxNode = X - 1;
	int MaxDist = 0;

	for (int i = 0; i < N; ++i)
	{
		if (m[i][X - 1] + m[X-1][i] > ans)
		{
			ans = m[i][X - 1] + m[X - 1][i];
		}
	}

	cout << ans;

	return 0;
}
