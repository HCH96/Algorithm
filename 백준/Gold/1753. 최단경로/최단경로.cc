#include <bits/stdc++.h>

#define ll long long

using namespace std;

int N, M, K, V, X, V1, V2, A, B, C, E;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E >> K;
	vector<vector<pair<int, int>>> edge(V+1);
	vector<int> dist(V+1, INT_MAX);

	for (int i = 0; i < E; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		edge[start].push_back({ end,cost });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	dist[K] = 0;
	pq.push({ 0,K });

	while (!pq.empty())
	{
		int CurNode = pq.top().second;
		int CurCost = pq.top().first;
		pq.pop();

		for (int i = 0; i < edge[CurNode].size(); ++i)
		{
			int nNode = edge[CurNode][i].first;
			int nCost = edge[CurNode][i].second;

			if (dist[nNode] > CurCost + nCost)
			{
				dist[nNode] = CurCost + nCost;
				pq.push({ CurCost + nCost,nNode });
			}
		}
	}

	for (int i = 1; i < V + 1; ++i)
	{
		if (dist[i] == INT_MAX)
			cout << "INF\n";
		else
			cout << dist[i] << endl;
	}

	return 0;
}
