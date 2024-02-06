#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int T, N, M, W;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	string s;
	cin >> s;

	int ans = 0;

	bool flag = false;

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == 'S')
			++ans;
		else if (!flag)
		{
			flag = true;
			ans += 2;
			++i;
		}
		else
		{
			ans += 1;
			++i;
		}
	}

	cout << ans;

	return 0;
}

