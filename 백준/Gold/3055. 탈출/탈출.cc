#include <iostream>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int Diff[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

int R, C;

void Water(vector<vector<char>>& v)
{
	vector<vector<char>> Tmp = v;

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (v[i][j] == '*')
			{
				for (int k = 0; k < 4; ++k)
				{
					int ny = i + Diff[k][0];
					int nx = j + Diff[k][1];

					if (ny < 0 || ny >= R || nx < 0 || nx >= C)
						continue;

					if (v[ny][nx] == '.')
						Tmp[ny][nx] = '*';
				}
			}
		}
	}

	v = Tmp;

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C;

	vector<vector<char>> v(R, vector<char>(C));
	vector<vector<bool>> visited(R, vector<bool>(C, false));
	queue<pair<int, int>> q;
	pair<int, int> Goal;
	pair<int, int> Start;

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cin >> v[i][j];
			if (v[i][j] == 'D')
			{
				Goal = { i,j };
			}

			if (v[i][j] == 'S')
			{
				Start = { i,j };
			}
		}
	}

	visited[Start.first][Start.second] = true;
	q.push({ Start.first, Start.second });
	int Time = 0;

	while (!q.empty())
	{
		Water(v);

		int QueueSize = q.size();

		for (int i = 0; i < QueueSize; ++i)
		{
			int CurRow = q.front().first;
			int CurCol = q.front().second;
			q.pop();

			if (CurRow == Goal.first && CurCol == Goal.second)
			{
				cout << Time;
				return 0;
			}

			for (int j = 0; j < 4; ++j)
			{
				int ny = CurRow + Diff[j][0];
				int nx = CurCol + Diff[j][1];

				if (ny < 0 || ny >= R || nx < 0 || nx >= C)
					continue;

				if (visited[ny][nx] == false && (v[ny][nx] == '.' || v[ny][nx] == 'D'))
				{
					visited[ny][nx] = true;
					q.push({ ny, nx });
				}
			}
		}

		++Time;
	}

	cout << "KAKTUS";



	return 0;
}
