#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int N;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int ans = 0;

	for (int i = 0; i < N; ++i)
	{
		int j = 0;

		while (j <= i)
		{
			ans += v[j];
			j++;
		}
	}

	cout << ans;

	return 0;
}
