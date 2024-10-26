#include <bits/stdc++.h>

using namespace std;

bool Sol(const vector<int>& Namu, int Height, int Target)
{
	long long sum = 0;

	for (int i = 0; i < Namu.size(); ++i)
	{
		if (Namu[i] > Height)
		{
			sum += Namu[i] - Height;
		}
	}

	if (sum >= Target)
		return true;
	else
		return false;
}

int Solution()
{
	int N, M;
	cin >> N >> M;

	vector<int> Namu;

	for (int i = 0; i < N; ++i)
	{
		int tmp;
		cin >> tmp;
		Namu.push_back(tmp);
	}

	int left = 0;
	int right = *max_element(Namu.begin(), Namu.end()) + 1;

	int ans = 0;

	while (left < right)
	{
		int mid = left + (right - left) / 2;

		if (Sol(Namu, mid, M))
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}

	cout << ans;

	return 0;
}
