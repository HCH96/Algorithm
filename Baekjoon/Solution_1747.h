#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, M;


bool ispalindrome(int i)
{
	string str = to_string(i);


	for (int i = 0; i < str.size() / 2; ++i)
	{
		if (str[i] != str[str.size() - i - 1])
			return false;
	}

	return true;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	int iMax = 1005000;

	vector<bool> v(iMax, true);

	v[0] = false;
	v[1] = false;

	for (int i = 2; i < iMax; ++i)
	{
		if (v[i] == false)
			continue;

		int tmp = i * 2;
		while (tmp < iMax)
		{
			v[tmp] = false;
			tmp += i;
		}

	}

	for (int i = N; i < iMax; ++i)
	{
		if (v[i] == true && ispalindrome(i))
		{
			cout << i;
			break;
		}
	}


	return 0;
}