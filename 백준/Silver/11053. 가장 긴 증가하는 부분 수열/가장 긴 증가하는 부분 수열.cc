#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <algorithm>


using namespace std;

int T, M, N, K, R, C, V, Ans;
int diff[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	vector<int> tmp;

	for (int i = 0; i < N; ++i)
	{
		int CurNumber = v[i];
		
		int j = 0;

		for (j = 0; j < tmp.size(); ++j)
		{
			if (CurNumber <= tmp[j])
				break;
		}

		if (j < tmp.size())
		{
			tmp[j] = CurNumber;
		}
		else
		{
			tmp.push_back(CurNumber);
		}

	}


	cout << tmp.size();


	return 0;
}