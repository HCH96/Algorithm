#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int N, M;

// ╩С, го, аб, ©Л
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	vector<vector<char>> v(N, vector<char>(N, '0'));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> v[i][j];
		}
	}

	queue<pair<int, int>> q;
	multiset<int> s;


	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (v[i][j] == '1')
			{
				int count = 0;

				v[i][j] = '0';
				q.push({ i,j });
				++count;

				while (!q.empty())
				{
					int y = q.front().first;
					int x = q.front().second;
					q.pop();

					for (int k = 0; k < 4; ++k)
					{
						int ny = y + dy[k];
						int nx = x + dx[k];

						if (nx >= 0 && nx < N && ny >= 0 && ny < N && v[ny][nx] == '1')
						{
							v[ny][nx] = '0';
							q.push({ ny,nx });
							++count;
						}
					}
				}

				s.insert(count);
			}
		}
	}

	cout << s.size() << endl;

	for (const auto& i : s)
	{
		cout << i << endl;
	}



	return 0;
}
