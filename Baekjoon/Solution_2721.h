#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int T, N, M, W;

void Sol(int n)
{
	vector<int> T(n + 2);

	T[0] = 0;

	for (int i = 1; i < n + 2; ++i)
	{
		T[i] = T[i - 1] + i;
	}

	int sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		sum += i * T[i + 1];
	}

	cout << sum << endl;

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--)
	{
		cin >> N;

		Sol(N);
	}


	return 0;
}

