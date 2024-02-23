#pragma once
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int N, M;

bool IsPossible(int target, vector<int>& v)
{
	int sum = 0;

	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] > target)
		{
			sum += target;
		}
		else
		{
			sum += v[i];
		}
	}

	if (sum > M)
		return false;
	else
		return true;
}

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

	cin >> M;

	sort(v.begin(), v.end());

	int left = 0;
	int right = v[N - 1];
	int ans = 0;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (IsPossible(mid, v))
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << ans;


	return 0;
}