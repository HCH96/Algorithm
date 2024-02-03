#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int T, N, M;

bool IsPossible(int Target, const vector<bool>& Gojang)
{
	if (Target < 0)
	{
		return false;
	}

	string tmp = to_string(Target);

	for (int i = 0; i < tmp.size(); ++i)
	{
		if (Gojang[tmp[i] - '0'] == true)
			return false;
	}


	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	vector<bool> Gojang(10, false);
	for (int i = 0; i < M; ++i)
	{
		int tmp;
		cin >> tmp;

		Gojang[tmp] = true;
	}


	int num = -1;
	int cha = 1;

	if (IsPossible(N, Gojang))
	{
		num = N;
	}

	while (num == -1 && M != 10)
	{
		if (IsPossible(N + cha, Gojang))
		{
			num = N + cha;
		}

		if (IsPossible(N - cha, Gojang))
		{
			num = N - cha;
		}

		++cha;
	}

	int ans = INT_MAX;


	if (num != -1)
	{
		ans = min(ans, abs(num - N));

		string strNum = to_string(num);

		ans += strNum.size();
	}


	ans = min(ans, abs(100 - N));
	cout << ans;

	return 0;
}

