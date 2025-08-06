#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<vector<long long>> MulMatrix(const vector <vector<long long>>& a, const vector<vector<long long>>& b)
{
	vector<vector<long long>> res(a.size(), vector<long long>(b[0].size(), 0));

	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = 0; j < b[0].size(); ++j)
		{
			for (int k = 0; k < a[0].size(); ++k)
			{
				res[i][j] += a[i][k] * b[k][j];
			}
			res[i][j] %= 1000000007;
		}
	}

	return res;
}

vector<vector<long long>> powMatrix(const vector<vector<long long>>& a, long long n) {

	if (n == 1)
	{
		return a;
	}

	vector<vector<long long>> Half = powMatrix(a, n / 2);
	vector<vector<long long>> res = MulMatrix(Half, Half);

	if (n % 2 == 1)
	{
		res = MulMatrix(res, a);
	}

	return res;
}

int main() {
	long long n;
	cin >> n;

	if (n < 2) {
		if (n == 0)
			cout << 0;
		else
			cout << 1;
		return 0;
	}

	vector<vector<long long>> init(2, vector<long long>(2));
	init[0][0] = 1;
	init[0][1] = 1;
	init[1][0] = 1;
	init[1][1] = 0;

	vector<vector<long long>> pibo(2, vector<long long>(1));
	pibo[0][0] = 1;
	pibo[1][0] = 0;

	vector<vector<long long>> res = powMatrix(init, n - 1);

	cout << MulMatrix(res, pibo)[0][0];

	return 0;
}