#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <unordered_map>

using namespace std;

int T, N, M, R, C,x,y;

int diff[4][2] = { {0,-1}, {0,1},{-1,0},{1,0} };



vector<pair<int,int>> Sol(vector<vector<char>>& v, int depth, pair<int,int> start)
{
	if (depth == 1)
	{
		v[start.first][start.second] = '*';

		v[start.first+1][start.second-1] = '*';
		v[start.first+1][start.second+1] = '*';
		
		v[start.first+2][start.second] = '*';
		v[start.first+2][start.second+1] = '*';
		v[start.first+2][start.second-1] = '*';
		v[start.first+2][start.second+2] = '*';
		v[start.first+2][start.second-2] = '*';

		vector<pair<int, int>> retVec;
		retVec.push_back({ start.first + 3,start.second - 3 });
		retVec.push_back({ start.first + 3,start.second + 3 });
		return retVec;
	}

	vector<pair<int,int>> Res = Sol(v, depth - 1, start); // up
	vector<pair<int,int>> ResLeft =Sol(v, depth - 1, Res[0]); // left
	vector<pair<int,int>> ResRight =Sol(v, depth - 1, Res[1]); // right

	vector<pair<int, int>> retVec2;
	retVec2.push_back(ResLeft[0]);
	retVec2.push_back(ResRight[1]);

	return retVec2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	vector<vector<char>> v(N, vector<char>(N * 2 - 1, ' '));
	
	int depth = 0;
	int tmp = N / 3;

	while (tmp > 0)
	{
		++depth;
		tmp /= 2;
	}
	
	Sol(v, depth, { 0,N - 1 });

	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[0].size(); ++j)
		{
			cout << v[i][j];
		}
		cout << endl;
	}




	return 0;
}
