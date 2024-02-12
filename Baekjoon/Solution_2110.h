#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int N, C;

bool isPossible(vector<int>& v, int target)
{
	int cnt = C;

	--cnt;
	int last = v[0];

	for (int i = 1; i < v.size(); ++i)
	{
		// 공유기를 놓을수 있다.
		if (v[i] - last >= target)
		{
			last = v[i];
			--cnt;
		}
	}

	if (cnt > 0)
		return false;
	else
		return true;

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> C;

	vector<int> v(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int low = 0;
	int high = v[N - 1];
	int mid;
	int ans = 0;


	while (low <= high)
	{
		mid = low + (high - low) / 2;

		// mid의 크기로 공유기를 설치할 수 있다.
		if (isPossible(v, mid))
		{
			ans = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	cout << ans;

	return 0;
}

