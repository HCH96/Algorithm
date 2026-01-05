#include <iostream>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int N;
int Diff[4][2] = { {1,0} , {0,1}, {-1,0} , {0,-1} };


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	vector<pair<long long,int>> PrefixSum(N + 1);
	PrefixSum[0] = { 0,0 };

	for (int i = 1; i <= N; ++i)
	{
		PrefixSum[i].first = PrefixSum[i - 1].first + v[i - 1];
		PrefixSum[i].second = i;
	}

	sort(PrefixSum.begin(), PrefixSum.end());

	long long CurMin = LLONG_MAX;
	pair<int, int> Answer = { -1,-1 };
	long long Ans = LLONG_MAX;

	for (int i = 1; i < N + 1; ++i)
	{
		long long diff = llabs(PrefixSum[i].first - PrefixSum[i - 1].first);
		
		if (diff < CurMin)
		{
			CurMin = diff;

			int a = PrefixSum[i - 1].second;
			int b = PrefixSum[i].second;

			int l = min(a, b) + 1;
			int r = max(a, b);

			Ans = a < b ? PrefixSum[i].first - PrefixSum[i - 1].first : PrefixSum[i - 1].first - PrefixSum[i].first;
			Answer = { l,r };
		}


	}

	cout << Ans << "\n" << Answer.first << " " << Answer.second;

	return 0;
}
