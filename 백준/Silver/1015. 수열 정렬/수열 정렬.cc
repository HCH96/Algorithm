#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <unordered_set>

using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	vector<pair<int, int>> v;

	for (int i = 0; i < N; ++i)
	{
		int t;
		cin >> t;

		v.push_back({ t,i });
	}

	sort(v.begin(), v.end());

	vector<int> Answer(N);

	for (int i = 0; i < N; ++i)
	{
		Answer[v[i].second] = i;
	}

	for (int i = 0; i < N; ++i)
	{
		cout << Answer[i] << " ";
	}

	return 0;
}
