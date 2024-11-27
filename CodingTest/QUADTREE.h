#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int C;

string Solution(string::iterator& iter)
{
	if (*iter != 'x')
	{
		char head = *iter;
		++iter;
		return string(1, head);
	}

	++iter;

	string First = Solution(iter);
	string Second = Solution(iter);
	string Third = Solution(iter);
	string Fourth = Solution(iter);


	return string("x") + Third + Fourth + First + Second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> C;

	while (C--)
	{
		string input;
		cin >> input;

		int Cur = 0;

		string::iterator iter = input.begin();

		string answer = Solution(iter);

		cout << answer << "\n";
	}

	return 0;
}
