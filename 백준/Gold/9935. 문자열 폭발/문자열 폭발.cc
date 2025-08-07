#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main() {

	string input, str;
	cin >> input >> str;

	stack<char> s;

	for (int i = 0; i < input.size(); ++i)
	{
		char CurChar = input[i];

		s.push(CurChar);

		stack<char> tmp;

		int Idx = str.size() - 1;

		while (!s.empty() && Idx>=0 && s.top() == str[Idx])
		{
			tmp.push(s.top());
			s.pop();
			--Idx;
		}

		if (tmp.size() != str.size())
		{
			while (!tmp.empty())
			{
				s.push(tmp.top());
				tmp.pop();
			}
		}
	}

	if (s.size() == 0)
	{
		cout << "FRULA";
	}
	else
	{
		deque<char> tmp;
		while (!s.empty())
		{
			tmp.push_front(s.top());
			s.pop();
		}

		for (int i = 0; i < tmp.size(); ++i)
		{
			cout << tmp[i];
		}
	}

	return 0;
}