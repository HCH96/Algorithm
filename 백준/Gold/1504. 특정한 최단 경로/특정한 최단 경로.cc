#include <bits/stdc++.h>

#define ll long long

using namespace std;

int N, M, K, V, X, V1, V2;

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

	cin >> N >> M;

	vector<vector<pair<int, int>>> edge(N);
	vector<vector<int>> m(N, vector<int>(N, INT_MAX));

	for (int i = 0; i < M; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;

		--start;
		--end;

		edge[start].push_back({ end,cost });
		edge[end].push_back({ start,cost });
	}

	cin >> V1 >> V2;

	--V1;
	--V2;
	
	Sol(edge, m[0], 0);
	Sol(edge, m[V1], V1);
	Sol(edge, m[V2], V2);
	
	int ans = INT_MAX;
	
	if (m[0][V1] != INT_MAX && m[V1][V2] != INT_MAX && m[V2][N - 1] != INT_MAX)
	{
		ans = m[0][V1] + m[V1][V2] + m[V2][N - 1];
	}

	if (m[0][V2] != INT_MAX && m[V2][V1] != INT_MAX && m[V1][N - 1] != INT_MAX)
	{
		ans = min(m[0][V2] + m[V2][V1] + m[V1][N - 1], ans);
	}

	if (ans == INT_MAX)
		ans = -1;

	cout << ans;

	return 0;
}
