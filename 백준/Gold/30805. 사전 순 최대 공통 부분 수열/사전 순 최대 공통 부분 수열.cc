#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;

	cin >> n;

	vector<pair<int,int>> a;
	vector<pair<int, int>> b;

	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		a.push_back({ num,i });
	}

	cin >> m; 
	
	for (int i = 0; i < m; ++i)
	{
		int num;
		cin >> num;
		b.push_back({ num,i });
	}

	sort(a.begin(), a.end(), cmp);
	sort(b.begin(), b.end(), cmp);

	vector<int> ans;

	int idxA = 0, idxB = 0, minA = 0, minB = 0;
	while (idxA < n && idxB < m)
	{
		if (a[idxA].first == b[idxB].first)
		{
			if (minA > a[idxA].second) ++idxA;
			else if (minB > b[idxB].second) ++idxB;
			else
			{
				ans.push_back(a[idxA].first);
				minA = a[idxA].second;
				minB = b[idxB].second;
				++idxA;
				++idxB;
			}
		}
		else if (a[idxA].first > b[idxB].first)
		{
			++idxA;
		}
		else
		{
			++idxB;
		}
	}

	cout << ans.size() << "\n";

	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}


	return 0;
}