#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int T, N, M, W;

int ans = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--)
	{
		vector<vector<int>> edge;

		// N : Node , M :Edge, W:WormHole
		cin >> N >> M >> W;

		bool ans = false;

		for (int i = 0; i < M; ++i)
		{
			int start, end, weight;
			cin >> start >> end >> weight;

			edge.push_back({ start,end,weight });
			edge.push_back({ end,start,weight });
		}

		for (int i = 0; i < W; ++i)
		{
			int start, end, weight;
			cin >> start >> end >> weight;

			edge.push_back({ start,end,-weight });
		}

		// 거리 정보를 저장할 배열 선언
		vector<int> dist(N + 1, 30000000);

		// 시작 지점
		dist[1] = 0;

		// K번 노드부터 시작하는 모든 최단 경로 계산
		for (int i = 1; i < N; ++i)
		{
			for (int j = 0; j < edge.size(); ++j)
			{
				int start = edge[j][0];
				int end = edge[j][1];
				int weight = edge[j][2];


				if (dist[start] + weight < dist[end])
					dist[end] = dist[start] + weight;
			}
		}

		// 음의 사이클 존재 확인
		for (int j = 0; j < edge.size(); ++j)
		{
			int start = edge[j][0];
			int end = edge[j][1];
			int weight = edge[j][2];

			if (dist[start] + weight < dist[end])
				ans = true;
		}

		if (ans)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}

