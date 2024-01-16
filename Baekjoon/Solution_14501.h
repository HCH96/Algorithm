#pragma once

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> t(n);
	vector<int> p(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> t[i] >> p[i];
	}

	// day, price
	queue<pair<int, int>> q;
	q.push({ 0,0 });

	int ans = 0;

	while (!q.empty())
	{
		int CurDay = q.front().first;
		int CurPrice = q.front().second;
		q.pop();

		ans = max(CurPrice, ans);

		if (CurDay >= n)
		{
			continue;
		}

		// CurDay에 상담을 하는 경우
		if (CurDay + t[CurDay] <= n)
		{
			q.push({ CurDay + t[CurDay], CurPrice + p[CurDay] });
		}

		// CurDay에 상담을 안하는 경우
		if (CurDay + 1 <= n)
		{
			q.push({ CurDay + 1, CurPrice });
		}
	}

	cout << ans;

	return 0;
}
