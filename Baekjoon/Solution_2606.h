#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int T, N, M;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	vector<vector<int>> v(N + 1);
	vector<bool> visited(N + 1, false);

	int start;
	int end;

	for (int i = 0; i < M; ++i)
	{
		cin >> start >> end;

		v[start].push_back(end);
		v[end].push_back(start);
	}

	queue<int> q;
	visited[1] = true;
	q.push(1);

	while (!q.empty())
	{
		int CurNode = q.front();
		q.pop();

		for (int i = 0; i < v[CurNode].size(); ++i)
		{
			int NextNode = v[CurNode][i];

			if (visited[NextNode] == false)
			{
				visited[NextNode] = true;
				q.push(v[CurNode][i]);
			}
		}
	}

	int ans = 0;
	for (int i = 2; i < visited.size(); ++i)
	{
		if (visited[i] == true)
			++ans;
	}

	cout << ans;

	return 0;
}