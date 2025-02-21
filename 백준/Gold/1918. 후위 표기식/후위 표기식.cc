#include <bits/stdc++.h>

#define ll long long

using namespace std;

int N, M, K, V, X, V1, V2, A, B, C, E, T, W;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	cin >> input;

	//  1순위 : *,/   
	//  2순위 : +,- 

	map<char, int> m;
	m['('] = 3;
	m[')'] = 3;
	m['*'] = 1;
	m['/'] = 1;
	m['+'] = 2;
	m['-'] = 2;


	stack<char> s;
	string ans;

	for (int i = 0; i < input.size(); ++i)
	{
		if (isalpha(input[i]))
		{
			ans.push_back(input[i]);
		} 
		else if (input[i] == '(' || input[i] == ')')
		{
			if (input[i] == '(')
			{
				s.push(input[i]);
			}
			else
			{
				while (!s.empty() && s.top() != '(')
				{
					ans.push_back(s.top());
					s.pop();
				}

				s.pop();
			}
		}
		else
		{
			if (s.empty())
			{
				s.push(input[i]);
			}
			else if (m[s.top()] <= m[input[i]])
			{
				while (!s.empty() && m[s.top()] <= m[input[i]])
				{
					ans.push_back(s.top());
					s.pop();
				}

				s.push(input[i]);
			}
			else
			{
				s.push(input[i]);
			}
		}
	}

	while (!s.empty())
	{
		ans.push_back(s.top());
		s.pop();
	}

	cout << ans;

	return 0;
}
