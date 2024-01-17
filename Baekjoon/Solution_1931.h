#pragma once

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct cmp
{
	bool operator()(pair<int, int>& first, pair<int, int>& second)
	{
		if (first.second == second.second)
			return first.first > second.first;
		return first.second > second.second;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;

	for (int i = 0; i < n; ++i)
	{
		int first, second;
		cin >> first >> second;
		q.push({ first,second });
	}

	int ans = 0;
	int Cur = 0;

	while (!q.empty())
	{
		if (q.top().first >= Cur)
		{
			Cur = q.top().second;
			++ans;
		}

		q.pop();
	}

	cout << ans;

	return 0;
}