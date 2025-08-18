#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, r;
	int ans = 0;

	cin >> n >> m >> r;

	vector<int> item(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> item[i];
	}

	vector<vector<pair<int, int>>> edge(n+1);
	for (int i = 0; i < r; ++i)
	{
		int s, e, w;
		cin >> s >> e >> w;
		edge[s].push_back({ e,w });
		edge[e].push_back({ s,w });
	}

	for (int i = 1; i <= n; ++i)
	{
		vector<int> dist(n + 1, INT_MAX);
		dist[i] = 0;

		queue<pair<int, int>> q;
		q.push({ i,0 });

		while (!q.empty())
		{
			int CurNode = q.front().first;
			int CurWeight = q.front().second;
			q.pop();

			if (dist[CurNode] != CurWeight)
				continue;

			for (int i = 0; i < edge[CurNode].size(); ++i)
			{
				int NextNode = edge[CurNode][i].first;
				int NextWeight = edge[CurNode][i].second;

				if (CurWeight + NextWeight <= m && CurWeight + NextWeight < dist[NextNode])
				{
					dist[NextNode] = CurWeight + NextWeight;
					q.push({ NextNode,CurWeight + NextWeight });
				}
			}
		}

		int sum = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (dist[i] <= m)
				sum += item[i];
		}
		ans = max(ans, sum);

	}

	cout << ans << "\n";

	return 0;
}