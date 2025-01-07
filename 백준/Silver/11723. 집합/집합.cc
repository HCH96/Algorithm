#include <bits/stdc++.h>
#include <unordered_map>
#include <deque>

using namespace std;

int T, N, M, V, H, K;
//int diff[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
//int diff3d[6][3] = { {-1,0,0}, {1,0,0}, {0,-1,0}, {0,1,0}, {0,0,1},{0,0,-1} };

int s[21];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M;

	string oper;
	int tmp;
	for (int i = 0; i < M; ++i)
	{
		cin >> oper;

		if (oper == "add")
		{
			cin >> tmp;

			s[tmp] = 1;
		}
		else if (oper == "check")
		{
			cin >> tmp;
			if (s[tmp])
			{
				cout << "1" << "\n";
			}
			else
			{
				cout << "0" << "\n";
			}
		}
		else if (oper == "remove")
		{
			cin >> tmp;
			s[tmp] = 0;
		}
		else if (oper == "toggle")
		{
			cin >> tmp;
			if (s[tmp])
			{
				s[tmp] = 0;
			}
			else
			{
				s[tmp] = 1;
			}
		}
		else if (oper == "all")
		{
			for (int k = 1; k <= 20; ++k)
			{
				s[k] = 1;
			}
		}
		else if (oper == "empty")
		{
			for (int k = 1; k <= 20; ++k)
			{
				s[k] = 0;
			}
		}


	}

	return 0;
}
