#include <bits/stdc++.h>

#define ll long long

using namespace std;

int N, M, K, V, X, V1, V2, A, B, C, E, T, W;

int maxDist;
int maxNode;

void Sol(const vector<vector<pair<int, int>>>& edge, vector<bool>& visited, int Cur, int Dist)
{
	if (visited[Cur] == true)
		return;

	visited[Cur] = true;

	if (maxDist < Dist)
	{
		maxDist = Dist;
		maxNode = Cur;
	}

	for (int i = 0; i < edge[Cur].size(); ++i)
	{
		Sol(edge, visited, edge[Cur][i].first, edge[Cur][i].second + Dist);
	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	vector<vector<pair<int, int>>> edge(N + 1);
	vector<bool> visited(N + 1, false);

	for (int i = 0; i < N-1; ++i)
	{
		int s, e, c;
		cin >> s >> e >> c;

		edge[s].push_back({ e, c });
		edge[e].push_back({ s, c });
	}

	
	maxNode = 1;
	maxDist = 0;

	Sol(edge, visited, 1, 0);


	for (int i = 0; i < visited.size(); ++i)
	{
		visited[i] = false;
	}

	Sol(edge, visited, maxNode, 0);

	cout << maxDist;

	return 0;
}
