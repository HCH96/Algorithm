#include <iostream>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int N;
int Diff[4][2] = { {1,0} , {0,1}, {-1,0} , {0,-1} };
		
int gcd(int a, int b)
{
	a = abs(a);
	b = abs(b);

	while (b != 0)
	{
		int t = a % b;
		a = b;
		b = t;
	}

	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	map<pair<int, int>, vector<vector<int>>> m;

	vector<pair<int, int>> Answer;

	for (int i = 0; i < N; ++i)
	{
		int x, y, z;
		cin >> x >> y >> z;

		int GCD = gcd(x, y);
		m[{x / GCD, y / GCD}].push_back({ x,y,z });
	}
	
	for (auto& [p,v] : m)
	{
		sort(v.begin(), v.end(), 
			[](const vector<int>& Left, const vector<int>& Right) -> bool{
				return (long long)Left[0] * Left[0] + (long long)Left[1] * Left[1] < (long long)Right[0] * Right[0] + (long long)Right[1] * Right[1];
		});

		int maxHeight = -1;

		for (const auto& it : v)
		{
			if (it[2] <= maxHeight)
			{
				Answer.push_back({ it[0],it[1] });
			}

			maxHeight = max(maxHeight, it[2]);
		}
	}

	sort(Answer.begin(), Answer.end(), [](pair<int, int>& Left, pair<int, int>& Right) {
		if (Left.first == Right.first)
			return Left.second < Right.second;
		return Left.first < Right.first;
		});

	for (int i = 0; i < Answer.size(); ++i)
	{
		cout << Answer[i].first << " " << Answer[i].second << "\n";
	}

	return 0;
}
