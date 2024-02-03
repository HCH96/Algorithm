#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int T, N, M;

int ans = 0;

bool check(vector<int>& v, int depth)
{
	for (int i = 0; i < depth; ++i)
	{
		if (v[i] == v[depth] || abs(v[i] - v[depth]) == depth - i)
			return false;
	}

	return true;
}


void sol(int depth, vector<int>& v)
{
	if (depth == N)
	{
		++ans;
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		v[depth] = i;

		if (check(v, depth))
		{
			sol(depth + 1, v);
		}
	}
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	vector<int> v(N, 0);

	sol(0, v);

	cout << ans;

	return 0;
}

