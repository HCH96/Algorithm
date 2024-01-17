#pragma once
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> v(n);

	int left = 0;
	int right = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		if (v[i] > right)
			right = v[i];
	}

	int ans = 0;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		ll sum = 0;

		for (int i = 0; i < n; ++i)
		{
			if (v[i] > mid)
			{
				sum += v[i] - mid;
			}
		}

		if (sum < m)
		{
			right = mid - 1;
		}
		else
		{
			if (mid > ans)
			{
				ans = mid;
			}
			left = mid + 1;
		}
	}

	cout << ans;

	return 0;
}