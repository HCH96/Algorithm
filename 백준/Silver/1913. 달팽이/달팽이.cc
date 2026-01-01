#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <unordered_set>

using namespace std;

int N;
int Diff[4][2] = { {1,0} , {0,1}, {-1,0} , {0,-1} };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	int k;
	cin >> k;
	vector<vector<int>> v(N, vector<int>(N, -1));

	int Count = pow(N, 2);

	int Cur = Count;
	int Row = 0;
	int Col = 0;
	int Dir = 0;

	for (int i = 0; i < Count; ++i)
	{
		v[Row][Col] = Cur--;

		if (Cur == 0)
			break;

		int NextRow, NextCol;
		while (true)
		{
			NextRow = Row + Diff[Dir][0];
			NextCol = Col + Diff[Dir][1];

			if (NextRow < 0 || NextRow >= N || NextCol < 0 || NextCol >= N || v[NextRow][NextCol] != -1)
			{
				Dir = (Dir + 1) % 4;
				continue;
			}

			break;
		}

		Row = NextRow;
		Col = NextCol;
	}


	pair<int, int> ans;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (v[i][j] == k)
			{
				ans = { i + 1,j + 1 };
			}
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

	cout << ans.first << " " << ans.second;

	return 0;
}
