#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <algorithm>


using namespace std;

int T, M, N, K, R, C, V, Ans;
int diff[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	vector<vector<int>> v(N, vector<int>(N, 0));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> v[i][j];
		}
	}

	for (int i = 1; i < N; ++i)
	{
		v[0][i] = v[0][i - 1] + v[0][i];
	}

	for (int i = 1; i < N; ++i)
	{
		v[i][0] = v[i-1][0] + v[i][0];
	}

	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j < N; ++j)
		{
			v[i][j] = v[i - 1][j] + v[i][j - 1] +v[i][j] - v[i-1][j-1];
		}
	}


	while (M--)
	{
		int Ans = 0;

		int StartX, StartY, EndX, EndY;

		cin >> StartY >> StartX >> EndY >> EndX;

		--StartY;
		--StartX;
		--EndY;
		--EndX;

		Ans = v[EndY][EndX];

		if(StartY>=1)
			Ans += -v[StartY - 1][EndX];
		if(StartX>=1)
			Ans += -v[EndY][StartX - 1];
		if(StartY>=1 && StartX>=1)
			Ans += v[StartY - 1][StartX - 1];
			

		cout << Ans << "\n";
	}

	



	return 0;
}