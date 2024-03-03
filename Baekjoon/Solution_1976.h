#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int N, M;

bool visited[200];
int m[200][200];


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> m[i][j];
		}
	}

	vector<int> Route;
	for (int i = 0; i < M; ++i)
	{
		int tmp;
		cin >> tmp;
		Route.push_back(tmp - 1);
	}


	int idx = 1;

	unordered_map<int, int> h;
	queue<int> q;

	for (int i = 0; i < N; ++i)
	{
		if (visited[i] == true)
		{
			continue;
		}

		visited[i] = true;
		q.push(i);

		while (!q.empty())
		{
			int Cur = q.front();
			h[Cur] = idx;

			q.pop();

			for (int j = 0; j < N; ++j)
			{
				if (visited[j] == false && m[Cur][j] == 1)
				{
					visited[j] = true;
					q.push(j);
				}
			}
		}

		++idx;
	}

	int Prev = Route[0];

	for (int i = 1; i < Route.size(); ++i)
	{
		int Cur = Route[i];

		if (h[Prev] != h[Cur])
		{
			cout << "NO";
			return 0;
		}

		Prev = Cur;
	}

	cout << "YES";



	return 0;
}
