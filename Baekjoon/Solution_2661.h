#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int T, N, M;

string ans = "Default";

bool isgood(const string& str)
{
	if (str.size() == 0)
		return true;

	// 12345 5 3
	// 123123 6 3
	for (int pos = str.size() - 1; pos >= (str.size() + 1) / 2; --pos)
	{
		int count = str.size() - pos;

		string sub1 = str.substr(pos, count);
		string sub2 = str.substr(pos - count, count);

		if (sub1 == sub2)
			return false;
	}

	return true;
}


void dfs(string& input)
{
	// 정답 x
	if (!isgood(input) || input.size() > N || ans != "Default")
		return;

	// 정답
	if (isgood(input) && input.size() == N && ans == "Default")
	{
		ans = input;
		return;
	}

	input += '1';
	dfs(input);
	input.pop_back();

	input += '2';
	dfs(input);
	input.pop_back();

	input += '3';
	dfs(input);
	input.pop_back();
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	string tmp = "";
	dfs(tmp);

	cout << ans;

	return 0;
}