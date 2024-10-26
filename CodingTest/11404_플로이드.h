#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> m(N, vector<int>(N, 10000000));

	for (int i = 0; i < M; ++i)
	{
		int start, end, weight;
		cin >> start >> end >> weight;

		m[start - 1][end - 1] = min(m[start - 1][end - 1], weight);
	}

	for (int i = 0; i < N; ++i)
	{
		m[i][i] = 0;
	}

	for (int k = 0; k < N; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (m[i][j] > m[i][k] + m[k][j])
				{
					m[i][j] = m[i][k] + m[k][j];
				}
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (m[i][j] == 10000000)
				cout << 0 << " ";
			else
				cout << m[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
