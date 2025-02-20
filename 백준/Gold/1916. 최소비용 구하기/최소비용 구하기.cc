#include <bits/stdc++.h>

#define ll long long

using namespace std;

int N, M, K, V, X, V1, V2, A, B, C, E, T, W;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	vector<vector<pair<int, int>>> edges(N+1);

	for (int i = 0; i < M; ++i)
	{
		int s, e, c;
		cin >> s >> e >> c;
		edges[s].push_back({ e,c });
	}

	cin >> A >> B;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(N + 1, INT_MAX);

	dist[A] = 0;
	pq.push({ 0,A });

	while (!pq.empty())
	{
		int CurNode = pq.top().second;
		int CurCost = pq.top().first;
		pq.pop();

		if (CurCost > dist[CurNode]) continue;

		for (int i = 0; i < edges[CurNode].size(); ++i)
		{
			int nNode = edges[CurNode][i].first;
			int nCost = edges[CurNode][i].second;

			if (dist[nNode] > dist[CurNode] + nCost)
			{
				dist[nNode] = dist[CurNode] + nCost;
				pq.push({ dist[nNode],nNode });
			}
		}
	}

	cout << dist[B];

	return 0;
}
