#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>

using namespace std;

int T, M, N, K, R, C, V, Ans;
int diff[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };


int GetKavinBacon(const vector<vector<int>>& Edge, int Target)
{
	vector<int> Dist(N + 1, -1);

	// 현재 위치
	queue<int> q;
	Dist[Target] = 0;
	q.push(Target);

	while (!q.empty())
	{
		int CurNode = q.front();
		q.pop();

		for (int i = 0; i < Edge[CurNode].size(); ++i)
		{
			int NextNode = Edge[CurNode][i];

			// 아직 방문하지 않은 경우
			if (Dist[NextNode] == -1)
			{
				Dist[NextNode] = Dist[CurNode] + 1;
				q.push(NextNode);
			}
		}
	}

	int KavinBacon = 0;

	for (int i = 1; i < N + 1; ++i)
	{
		if (Dist[i] == -1)
		{
			continue;
		}

		KavinBacon += Dist[i];
	}

	return KavinBacon;
}


int main()
{
	cin >> N >> M;

	vector<vector<int>> Edge(N + 1);

	for (int i = 0; i < M; ++i)
	{
		int Start, End;
		cin >> Start >> End;

		Edge[Start].push_back(End);
		Edge[End].push_back(Start);
	}

	vector<int> KavinBacon(N + 1);

	for (int i = 1; i < N + 1; ++i)
	{
		KavinBacon[i] = GetKavinBacon(Edge, i);
	}

	int Answer = 0;
	int MinValue = 10000;


	for (int i = 1; i < N + 1; ++i)
	{
		if (KavinBacon[i] < MinValue)
		{
			MinValue = KavinBacon[i];
			Answer = i;
		}
	}

	cout << Answer;

	return 0;
}