#include <bits/stdc++.h>
#include <unordered_map>
#include <deque>

using namespace std;

int T, N, M, V, H, K;
//int diff[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
//int diff3d[6][3] = { {-1,0,0}, {1,0,0}, {0,-1,0}, {0,1,0}, {0,0,1},{0,0,-1} };


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	priority_queue<int> pq;

	for (int i = 0; i < N; ++i)
	{
		cin >> T;

		if (T == 0)
		{
			if (pq.size() == 0)
			{
				cout << 0 << "\n";
			}
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
		{
			pq.push(T);
		}
	}


	return 0;
}
