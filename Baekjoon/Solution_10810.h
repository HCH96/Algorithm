#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int N, M;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	vector<int> v(N + 1, -1);

	for (int i = 0; i < M; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		for (int j = a; j <= b; ++j)
		{
			v[j] = c;
		}
	}

	for (int i = 1; i < N + 1; ++i)
	{
		if (v[i] == -1)
			cout << 0 << " ";
		else
			cout << v[i] << " ";
	}


	return 0;
}
