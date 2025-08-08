#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> arr;

	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	vector<int> leftdp(n,1);
	vector<int> rightdp(n,1);

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[i] > arr[j])
			{
				leftdp[i] = max(leftdp[i], leftdp[j] + 1);
			}
		}
	}

	for (int i = n - 2; i >= 0; --i)
	{
		for (int j = n - 1; j > i; --j)
		{
			if (arr[i] > arr[j])
			{
				rightdp[i] = max(rightdp[i], rightdp[j] + 1);
			}
		}
	}

	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		if (answer < leftdp[i] + rightdp[i] - 1)
		{
			answer = leftdp[i] + rightdp[i] - 1;
		}
	}


	cout << answer;

	return 0;
}