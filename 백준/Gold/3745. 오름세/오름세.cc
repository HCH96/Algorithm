#include <iostream>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int N;
vector<int> v;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> N)
	{
		v.clear();
		v.resize(N);

		for (int i = 0; i < N; ++i)
		{
			cin >> v[i];
		}

		vector<int> LIS;
		vector<int> Prev(N);
		vector<int> IdxArr;

		for (int i = 0; i < N; ++i)
		{
			int Cur = v[i];

			int Idx = lower_bound(LIS.begin(), LIS.end(), Cur) - LIS.begin();

			if (Idx == LIS.size())
			{
				LIS.push_back(Cur);
				IdxArr.push_back(i);

				if (Idx == 0)
				{
					Prev[i] = -1;
				}
				else
				{
					Prev[i] = IdxArr[Idx - 1];
				}
			}
			else
			{
				LIS[Idx] = Cur;
				IdxArr[Idx] = i;

				if (Idx == 0)
				{
					Prev[i] = -1;
				}
				else
				{
					Prev[i] = IdxArr[Idx - 1];
				}
			}
		}

		int CurIdx = IdxArr[IdxArr.size() - 1];
		stack<int> Answer;

		while (CurIdx != -1)
		{
			Answer.push(v[CurIdx]);
			CurIdx = Prev[CurIdx];
		}

		cout << Answer.size() << "\n";

	}


	return 0;
}
