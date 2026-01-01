#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <unordered_set>

using namespace std;

int N, K, T;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;

	while (T--)
	{
		int Answer = 0;
		string s;
		cin >> s;

		for (int i = 0; i < s.size(); ++i)
		{
			char Cur = s[i];

			Answer += min(Cur - 'A', 'Z' - Cur + 1);
		}

		vector<int> idx;

		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] != 'A')
				idx.push_back(i);
		}

		if (idx.size() != 0)
		{
			int MinMove = INT_MAX;
			int Size = s.size();

			for (int i = 1; i < idx.size(); ++i)
			{
				MinMove = min(MinMove, 2 * idx[i - 1] + (Size - idx[i]));
				MinMove = min(MinMove, (Size - idx[i]) * 2 + idx[i - 1]);
			}

			MinMove = min(MinMove, idx[idx.size() - 1]);
			MinMove = min(MinMove, Size - idx[0]);

			Answer += MinMove;
		}

		

		cout << Answer << endl;
	}
 

	return 0;
}
