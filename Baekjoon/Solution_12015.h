#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int N;

void exchange(vector<int>& v, int target)
{
	int low = 0;
	int high = v.size() - 1;
	int mid;

	while (low < high)
	{
		int mid = low + (high - low) / 2;

		if (v[mid] < target)
		{
			low = mid + 1;
		}
		else
		{
			high = mid;
		}
	}

	v[high] = target;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	vector<int> v;

	for (int i = 0; i < N; ++i)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	vector<int> ans;
	ans.push_back(v[0]);

	for (int i = 1; i < N; ++i)
	{
		if (v[i] > ans.back())
		{
			ans.push_back(v[i]);
		}
		else
		{
			exchange(ans, v[i]);
		}
	}

	cout << ans.size();

	return 0;
}
