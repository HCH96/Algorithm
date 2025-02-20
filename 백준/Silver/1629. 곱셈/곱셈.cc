#include <bits/stdc++.h>

#define ll long long

using namespace std;

int N, M, K, V, X, V1, V2, A, B, C;

ll Sol(int a, int b, int c)
{
	if (b == 1)
		return a % c;

	ll left;
	ll right;

	if (b % 2 == 0)
	{
		left = Sol(a, b / 2, c);
		right = Sol(a, b / 2, c);
	}
	else
	{
		left = Sol(a, b / 2, c);
		right = Sol(a, b / 2 + 1, c);
	}

	return (left * right) % c;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;

	ll ans = Sol(A, B, C);
	cout << ans;


	return 0;
}
