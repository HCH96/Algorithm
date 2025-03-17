#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int N, M;

// 상, 하, 좌, 우
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
bool visited[2][1000][1000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	vector<vector<int>> v(N, vector<int>(M));
	int ans = INT_MAX;

	// y, x , 남은 벽 제거 횟수
	queue<vector<int>> q;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			char c;
			cin >> c;
			v[i][j] = c - '0';
		}
	}

	visited[1][0][0] = true;
	q.push({ 0,0,1,1 });

	while (!q.empty())
	{
		int y = q.front()[0];
		int x = q.front()[1];
		int cnt = q.front()[2];
		int route = q.front()[3];
		q.pop();

		// 정답
		if (y == N - 1 && x == M - 1)
		{
			cout << route;
			return 0;
		}

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && ny < N && nx >= 0 && nx < M)
			{
				int leftCnt = cnt - v[ny][nx];

				// 더 이상 벽을 부술 수 없거나, 이미 방문한 경우
				if (leftCnt < 0 || visited[leftCnt][ny][nx] == true)
				{
					continue;
				}

				visited[leftCnt][ny][nx] = true;
				q.push({ ny,nx,leftCnt,route + 1 });
			}
		}
	}

	cout << -1;

	return 0;
}
