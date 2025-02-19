#include <bits/stdc++.h>

using namespace std;

int N, M, K, V;

int MaxNode;
int MaxDist;

void Sol(const vector<vector<pair<int, int>>>& edge, vector<bool>& visited, int Cur, int CurDist)
{
	if (visited[Cur] == true)
		return;

	visited[Cur] = true;

	if (CurDist > MaxDist)
	{
		MaxDist = CurDist;
		MaxNode = Cur;
	}

	for (int i = 0; i < edge[Cur].size(); ++i)
	{
		Sol(edge, visited, edge[Cur][i].first, CurDist + edge[Cur][i].second);
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V;

	vector<vector<pair<int,int>>> edge(V);
	vector<bool> visited(V, false);

	for (int i = 0; i < V; ++i)
	{
		int Cur;
		cin >> Cur;

		int Next, Cost;

		while (true)
		{
			cin >> Next;

			if (Next == -1)
				break;

			cin >> Cost;

			edge[Cur-1].push_back({ Next-1,Cost });
		}
	}

	MaxNode = 0;
	MaxDist = 0;

	Sol(edge, visited, 0, 0);

	MaxDist = 0;
	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
	}
	
	Sol(edge, visited, MaxNode, 0);

	cout << MaxDist;

	return 0;
}
