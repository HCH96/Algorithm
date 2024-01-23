#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, M;

// ╩С, го, аб, ©Л 
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;

	cin >> N >> M >> k;

	vector<vector<int>> v(N, vector<int>(M, 0));

	for (int i = 0; i < k; ++i)
	{
		// x, y
		pair<int, int> LeftTop;
		pair<int, int> RightBottom;

		cin >> LeftTop.first >> LeftTop.second;
		cin >> RightBottom.first >> RightBottom.second;

		for (int row = LeftTop.second; row < RightBottom.second; ++row)
		{
			for (int col = LeftTop.first; col < RightBottom.first; ++col)
			{
				v[row][col] = 1;
			}
		}
	}

	int ans = 0;
	vector<int> size;

	queue<pair<int, int>>  q;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (v[i][j] == 0)
			{
				++ans;
				int tmp = 0;
				// bfs
				v[i][j] = 1;
				q.push({ i,j });

				while (!q.empty())
				{
					int CurRow = q.front().first;
					int CurCol = q.front().second;
					++tmp;
					q.pop();

					for (int i = 0; i < 4; ++i)
					{
						int y = CurRow + dy[i];
						int x = CurCol + dx[i];

						if (y >= 0 && y < N && x >= 0 && x < M && v[y][x] == 0)
						{
							v[y][x] = 1;
							q.push({ y,x });
						}
					}
				}

				size.push_back(tmp);
			}
		}
	}


	sort(size.begin(), size.end());
	cout << ans << endl;

	for (int i = 0; i < size.size(); ++i)
	{
		cout << size[i] << " ";
	}


	return 0;
}