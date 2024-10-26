#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int from, to, cost;
};

int main()
{
	int n, m;
	cin >> n >> m;

	vector<Edge> edges(m);
	vector<long long> dist(n + 1, LLONG_MAX);


	for (int i = 0; i < m; ++i)
	{
		cin >> edges[i].from >> edges[i].to >> edges[i].cost;
	}

	dist[1] = 0;

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int start = edges[j].from;
			int end = edges[j].to;
			int cost = edges[j].cost;

			if (dist[start] != LLONG_MAX && dist[start] + cost < dist[end])
			{
				dist[end] = dist[start] + cost;
			}
		}
	}

	bool check = false;

	for (int j = 0; j < m; ++j)
	{
		int start = edges[j].from;
		int end = edges[j].to;
		int cost = edges[j].cost;

		if (dist[start] != LLONG_MAX && dist[start] + cost < dist[end])
		{
			check = true;
		}
	}

	if (check)
	{
		cout << -1 << endl;
	}
	else
	{
		for (int i = 2; i <= n; ++i)
		{
			if (dist[i] == LLONG_MAX)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << dist[i] << endl;
			}
		}
	}

	return 0;
}
