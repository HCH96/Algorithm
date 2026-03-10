#include <iostream>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int R, C;
vector<vector<int>> Arr;
vector<vector<int>> Answer;
vector<vector<pair<int, int>>> DP;

int Diff[8][2] = { {-1,0},{-1,-1},{-1,1},{1,-1},{1,0},{1,1},{0,-1},{0,1} };

pair<int,int> Sol(int y, int x)
{
	pair<int, int> p = DP[y][x];

	if (p != make_pair(-1,-1))
	{
		++Answer[p.first][p.second];
		return DP[y][x];
	}

	int MinVal = Arr[y][x];
	DP[y][x] = { y,x };
	p = { y,x };

	for (int i = 0; i < 8; ++i)
	{
		int NextY = y + Diff[i][0];
		int NextX = x + Diff[i][1];

		if (NextY < 0 || NextY >= R || NextX < 0 || NextX >= C)
			continue;

		if (Arr[NextY][NextX] < MinVal)
		{
			p = { NextY , NextX };
			MinVal = Arr[NextY][NextX];
		}
	}

	return DP[y][x] = Sol(p.first, p.second);

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C;

	Arr.resize(R, vector<int>(C, -1));
	Answer.resize(R, vector<int>(C, 0));
	DP.resize(R, vector<pair<int, int>>(C, { -1,-1 }));

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cin >> Arr[i][j];
		}
	}

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			Sol(i, j);
		}
	}


	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cout << Answer[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
