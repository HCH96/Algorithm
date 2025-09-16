#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N;
bool findCycle;
vector<int> pre;
vector<bool> visited;
vector<int> dist;
vector<int> cycle;

void DFS(int Cur, const vector<vector<int>>& edge)
{
	visited[Cur] = true;

	for (auto Next : edge[Cur])
	{
		if (Next == pre[Cur])
			continue;

		if (findCycle)
			break;

		if (visited[Next] == false)
		{
			pre[Next] = Cur;
			DFS(Next,edge);
		}
		else
		{
			findCycle = true;

			int Parent = Next;

			while (Cur != Parent)
			{
				cycle.push_back(Cur);
				dist[Cur] = 0;
				Cur = pre[Cur];
			}
			
			cycle.push_back(Cur);
			dist[Cur] = 0;

			return;
		}
	}
}

void BFS(vector<vector<int>>& edge)
{
	queue<int> q;

	for (auto i : cycle)
	{
		q.push(i);
	}

	while (!q.empty())
	{
		int Cur = q.front();
		q.pop();

		for (auto Next : edge[Cur])
		{
			if (dist[Next] == 0)
			{
				continue;
			}

			if (dist[Next] == -1)
			{
				dist[Next] = dist[Cur] + 1;
				q.push(Next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	vector<vector<int>> edge(N + 1);
	pre.resize(N + 1, -1);
	visited.resize(N + 1, false);
	dist.resize(N + 1, -1);
	for (int i = 0; i < N; ++i)
	{
		int s, e;
		cin >> s >> e;
		edge[s].push_back(e);
		edge[e].push_back(s);
	}

	DFS(1,edge);

	BFS(edge);

	for (int i = 1; i <= N; ++i)
	{
		cout << dist[i] << " ";
	}


	return 0;
}