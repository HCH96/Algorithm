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


	int Answer = -1;
	vector<long long> v(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	unordered_set<long long> s;

	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			s.insert(v[i] + v[j]);
		}
	}

	for (int i = N - 1; i >= 0; --i)
	{
		long long d = v[i];

		for (int j = 0; j < N; ++j)
		{
			long long Target = d - v[j];

			if (s.find(Target) != s.end())
			{
				Answer = d;
			}
		}
		if (Answer != -1)
			break;
	}

	if (Answer == -1)
	{
		cout << "no solution\n";
	}
	else
	{
		cout << Answer << endl;
	}


	return 0;
}
