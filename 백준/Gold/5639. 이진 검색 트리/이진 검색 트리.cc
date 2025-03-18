#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <set>

using namespace std;

int T, N, M, R, C,x,y;

int diff[4][2] = { {0,-1}, {0,1},{-1,0},{1,0} };

void Sol(const vector<int>& v, int left, int right)
{
	if (left >= right)
		return;

	int mid = left + 1;

	for (; mid < right; ++mid)
	{
		if (v[left] < v[mid])
		{
			break;
		}
	}

	Sol(v, left + 1, mid);
	Sol(v, mid, right);
	cout << v[left] << endl;

	return;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;

	while (cin >> x) {
		v.push_back(x);
	}

	Sol(v,0,v.size());

	return 0;
}

