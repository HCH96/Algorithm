#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <set>

using namespace std;

int T, N, M, R, C,x,y;

int diff[4][2] = { {0,-1}, {0,1},{-1,0},{1,0} };

void Clear(vector<vector<int>>& v)
{
	vector<vector<bool>> visited(N, vector<bool>(M, false));

	queue<pair<int, int>> q;
	
	visited[0][0] = true;
	v[0][0] = 2;
	q.push({ 0,0 });

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + diff[i][0];
			int nx = x + diff[i][1];

			if (ny >= 0 && ny < N && nx >= 0 && nx < M && visited[ny][nx] == false && (v[ny][nx] == 0||v[ny][nx]==2))
			{
				visited[ny][nx] = true;
				v[ny][nx] = 2;
				q.push({ ny,nx });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	vector<vector<int>> v(N, vector<int>(M, 0));
	queue<pair<int, int>> q;
	queue<pair<int, int>> DeleteCheeze;
	int ans = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> v[i][j];
			if (v[i][j] == 1)
			{
				q.push({ i,j });
			}
		}
	}

	while (!q.empty())
	{
		++ans;

		Clear(v);

		int cnt = q.size();
		while (cnt > 0)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			int aircnt = 0;
			
			for (int i = 0; i < 4; ++i)
			{
				int ny = y + diff[i][0];
				int nx = x + diff[i][1];
				
				if (ny >= 0 && ny < N && nx >= 0 && nx < M && v[ny][nx] == 2)
				{
					++aircnt;
				}
			}

			if (aircnt < 2)
			{
				q.push({ y,x });
			}
			else
			{
				DeleteCheeze.push({ y,x });
			}

			--cnt;
		}

		// 치즈 삭제
		while (!DeleteCheeze.empty())
		{
			v[DeleteCheeze.front().first][DeleteCheeze.front().second] = 0;
			DeleteCheeze.pop();
		}
	}

	cout << ans;



	return 0;
}

