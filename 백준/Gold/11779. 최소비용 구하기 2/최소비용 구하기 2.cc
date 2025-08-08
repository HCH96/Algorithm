#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> edge(n+1);

	for (int i = 0; i < m; ++i)
	{
		int s, e, w;
		cin >> s >> e >> w;

		edge[s].push_back({ e,w });
	}

	int start, end;
	cin >> start >> end;

	// weight, end
	priority_queue<pair<int, int>> pq;

	vector<int> dist(n + 1, INT_MAX);
	vector<int> prev(n + 1, -1);

	dist[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty())
	{
		int Cur = pq.top().second;
		int Weight = -pq.top().first;
		pq.pop();

		if (Weight != dist[Cur]) continue;

		for (int i = 0; i < edge[Cur].size(); ++i)
		{
			int Next = edge[Cur][i].first;
			int NextWeight = edge[Cur][i].second;

			if (dist[Next] > Weight + NextWeight)
			{
				dist[Next] = Weight + NextWeight;
				prev[Next] = Cur;

				pq.push({ -(Weight + NextWeight) , Next });
			}
		}
	}

	cout << dist[end] << "\n";

	stack<int> s;
	int tmp = end;

	while (tmp != -1)
	{
		s.push(tmp);
		tmp = prev[tmp];
	}

	cout << s.size() << "\n";

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}