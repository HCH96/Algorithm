#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int T, N, K, B;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K >> B;

	vector<bool> v(N + 1, true);

	for (int i = 0; i < B; ++i)
	{
		int tmp;
		cin >> tmp;
		v[tmp] = false;
	}

	int cnt = 0;
	int ans = INT_MAX;


	for (int i = 1; i <= K; ++i)
	{
		if (v[i] == false)
			++cnt;
	}

	ans = min(ans, cnt);

	for (int i = K + 1; i < N + 1; ++i)
	{
		if (v[i] == false)
			++cnt;
		if (v[i - K] == false)
			--cnt;

		ans = min(ans, cnt);
	}

	cout << ans;


	return 0;
}

