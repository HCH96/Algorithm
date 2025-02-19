#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<int> FailFunction(const string& Pattern)
{
	int m = Pattern.size();
	vector<int> fail(m, 0);
	int j = 0;

	for (int i = 1; i < m; ++i) 
	{
		while (j > 0 && Pattern[i] != Pattern[j])
		{
			j = fail[j - 1];
		}

		if (Pattern[i] == Pattern[j])
		{
			fail[i] = ++j;
		}
	}

	return fail;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string Text;
	int ans = 0;

	cin >> N >> M >> Text;

	string Pattern = "I";

	for (int i = 0; i < N; ++i)
	{
		Pattern += "OI";
	}

	vector<int> Fail = FailFunction(Pattern);
	
	int j = 0;

	for (int i = 0; i < M; ++i)
	{
		while (j > 0 && Text[i] != Pattern[j])
		{
			j = Fail[j-1];
		}

		if (Text[i] == Pattern[j])
		{
			if (j == Pattern.size() - 1)
			{
				++ans;
				j = Fail[j];
			}
			else
			{
				++j;
			}
		}
	}

	cout << ans;

	return 0;
}
