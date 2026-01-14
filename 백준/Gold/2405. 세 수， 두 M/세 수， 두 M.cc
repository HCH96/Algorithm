#include <iostream>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int N, M;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	long long Answer = LLONG_MIN;

	vector<int> v(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	for (int i = 1; i < N-1; ++i)
	{
		Answer = max(Answer, llabs((long long)v[i - 1] + v[N - 1] - 2 * v[i]));
		Answer = max(Answer, llabs((long long)v[0] + v[i + 1] - 2 * v[i]));
	}

	cout << Answer;


	return 0;
}
