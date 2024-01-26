#include <bits/stdc++.h>
#include <unordered_map>


using namespace std;

typedef long long ll;

int T, N, M;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--)
	{
		cin >> N;

		vector<pair<int, int>> v;

		for (int i = 0; i < N; ++i)
		{
			pair<int, int> p;
			cin >> p.first >> p.second;

			v.push_back(p);
		}

		sort(v.begin(), v.end());

		int minVal = v[0].second;
		int ans = 1;

		for (int i = 1; i < v.size(); ++i)
		{
			// i가 더 좋은 성적
			if (v[i].second < minVal)
			{
				minVal = v[i].second;
				++ans;
			}
		}

		cout << ans << endl;
	}


	return 0;
}