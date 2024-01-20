#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M;

bool sol(vector<int> v)
{
	vector<bool> flag(v.size(), false);

	int Prev = v[0];


	int i = 1;

	while (i < v.size())
	{
		if (Prev == v[i])
		{
			++i;
			continue;
		}

		if (Prev < v[i])
		{
			if ((v[i] - Prev) > 1)
				return false;

			for (int j = 1; j <= M; ++j)
			{
				if ((i - j) < 0)
					return false;

				if (flag[i - j])
					return false;

				if (v[i - j] != Prev)
					return false;

				flag[i - j] = true;
			}
			Prev = v[i];
			++i;
		}
		else if (Prev > v[i])
		{
			if ((Prev - v[i]) > 1)
				return false;

			for (int j = 0; j < M; ++j)
			{
				if ((i + j) >= v.size())
					return false;
				if (flag[i + j])
					return false;

				if (v[i + j] != v[i])
					return false;

				flag[i + j] = true;
			}
			Prev = v[i];
			i = i + M;
		}
	}

	return true;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	vector<vector<int>> m(N, vector<int>(N));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> m[i][j];
		}
	}

	int ans = 0;

	for (int i = 0; i < N; ++i)
	{
		if (sol(m[i]))
			++ans;
	}

	for (int i = 0; i < N; ++i)
	{
		vector<int> tmp;
		for (int j = 0; j < N; ++j)
		{
			tmp.push_back(m[j][i]);
		}

		if (sol(tmp))
			++ans;
	}

	cout << ans;

	return 0;
}