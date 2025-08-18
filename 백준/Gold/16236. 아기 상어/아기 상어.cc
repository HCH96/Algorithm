#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int n;

int board[20][20];
pair<int, int> CurPos;

int CurLevel = 2;
int CurCnt = 0;

int diff[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

void Find(vector<vector<int>>& v)
{
	int Time = 0;

	vector<vector<bool>> visited(n, vector<bool>(n,false));
	queue<vector<int>> q;

	q.push({ CurPos.first,CurPos.second ,0 });
	visited[CurPos.first][CurPos.second] = true;

	while(!q.empty())
	{
		int y = q.front()[0];
		int x = q.front()[1];
		int CurDist = q.front()[2];
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + diff[i][0];
			int nx = x + diff[i][1];

			if (ny >= 0 && ny < n && nx >= 0 && nx < n && visited[ny][nx] == false)
			{
				if (board[ny][nx] == 0 || board[ny][nx] == CurLevel)
				{
					visited[ny][nx] = true;
					q.push({ ny,nx, CurDist+1 });
				}
				else if (board[ny][nx] < CurLevel)
				{
					visited[ny][nx] = true;
					v.push_back({ ny,nx,CurDist + 1 });
				}
				else
				{
					visited[ny][nx] = true;
				}
			}
		}
	}

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] == 9)
				CurPos = { i,j };
		}
	}

	int ans = 0;

	while (true)
	{


		vector<vector<int>> Candi;

		Find(Candi);

		if (Candi.size() == 0)
			break;

		sort(Candi.begin(), Candi.end(), [](const vector<int>& a, const vector<int>& b) {

			if (a[2] == b[2])
			{
				if (a[0] == b[0])
					return a[1] < b[1];

				return a[0] < b[0];
			}

			return a[2] < b[2];
			});

		int Time = Candi[0][2];
		ans += Time;

		board[Candi[0][0]][Candi[0][1]] = 9;
		board[CurPos.first][CurPos.second] = 0;
		CurPos.first = Candi[0][0];
		CurPos.second = Candi[0][1];

		++CurCnt;

		if (CurCnt >= CurLevel)
		{
			CurCnt = 0;
			++CurLevel;
		}
	}

	cout << ans << "\n";

	return 0;
}