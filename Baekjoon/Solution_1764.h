#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int N, M;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	set<string> s;
	set<string> ans;


	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;
		s.insert(str);
	}

	for (int i = 0; i < M; ++i)
	{
		string str;
		cin >> str;
		if (s.find(str) != s.end())
		{
			ans.insert(str);
		}

	}

	set<string>::iterator iter = ans.begin();
	cout << ans.size() << endl;

	for (; iter != ans.end(); ++iter)
	{
		cout << *iter << endl;

	}




	return 0;
}
