#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
	vector<vector<pair<int, int>>> edge(N+1);

	for (int i = 0; i < road.size(); ++i)
	{
		int s = road[i][0];
		int e = road[i][1];
		int w = road[i][2];

		edge[s].push_back({ e,w });
		edge[e].push_back({ s,w });
	}


	
	
	vector<int> Dist(N + 1, INT_MAX);
	// 거리, 노드
	priority_queue<pair<int, int>> pq;

	Dist[1] = 0;
	pq.push({ 0,1 });

	while (!pq.empty())
	{
		int CurCost = -pq.top().first;
		int CurNode = pq.top().second;
		pq.pop();

		for (int i = 0; i < edge[CurNode].size(); ++i)
		{
			if (CurCost + edge[CurNode][i].second < Dist[edge[CurNode][i].first])
			{
				Dist[edge[CurNode][i].first] = CurCost + edge[CurNode][i].second;
				pq.push({ -Dist[edge[CurNode][i].first] , edge[CurNode][i].first });
			}
		}
	}

	int Answer =0;

	for (int i = 0; i < Dist.size(); ++i)
	{
		if (Dist[i] <= K)
			++Answer;
	}


	return Answer;
}