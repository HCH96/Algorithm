#pragma once

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int N, L, D;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L >> D;

	int CurTime = 0;
	int lastMusic = N * (L + 5);
	int ans = 0;


	while (true)
	{
		if (CurTime >= lastMusic)
		{
			ans = CurTime;
			break;
		}

		if ((CurTime % (L + 5)) >= L)
		{
			ans = CurTime;
			break;
		}

		CurTime += D;
	};

	cout << ans;

	return 0;
}