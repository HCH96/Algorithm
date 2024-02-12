#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int T, N, K, B;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	priority_queue<int> q;

	for (int i = 0; i < N; ++i)
	{
		cin >> K;

		if (K == 0)
		{
			if (q.empty())
			{
				cout << 0 << "\n";
			}
			else
			{
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else
		{
			q.push(K);
		}

	}

	return 0;
}