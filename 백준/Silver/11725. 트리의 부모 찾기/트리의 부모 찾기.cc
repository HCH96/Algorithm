#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, M;

int main() {

	cin >> N;

	vector<vector<int>> adj(N + 1);
	vector<bool> visited(N + 1, false);
	vector<int> answer(N + 1, 0);

	for (int i = 0; i < N - 1; ++i)
	{
		int s, e;
		cin >> s >> e;

		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	queue<int> q;
	visited[1] = true;
	q.push(1); 

	while (!q.empty())
	{
		int Cur = q.front();
		q.pop();

		for (int i = 0; i < adj[Cur].size(); ++i)
		{
			int next = adj[Cur][i];
			if (!visited[next])
			{
				answer[next] = Cur;
				visited[next] = true;
				q.push(next);
			}
		}
	}

	for (int i = 2; i < N + 1; ++i)
	{
		cout << answer[i] << "\n";
	}


	return 0;
}