#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <unordered_set>

using namespace std;

int N, K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;


	vector<int> v(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	int a = 0, b = 0;


	for (int i = 0; i < K; ++i)
	{
		if (v[i] == 1)
		{
			++a;
		}
		else
		{
			++b;
		}
	}

	int idx = K;
	int Answer = 0;

	while (a != 0 || b != 0)
	{
		int Count = 0;

		if (a > 0 && b > 0)
		{
			--a;
			--b;
			Count += 2;
		}
		else if (a > 0 && b == 0)
		{
			--a;
			++Count;
		}
		else if (a == 0 && b > 0)
		{
			--b;
			++Count;
		}

		while (Count-- && idx < N)
		{
			if (v[idx] == 1)
			{
				++a;
			}
			else
			{
				++b;
			}

			++idx;
		}


		++Answer;
	}

	cout << Answer;
	return 0;
}
