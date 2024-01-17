#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> v;
set<int> s;
set<tuple<int, int, int>> s2;

void dfs(vector<int> Cur)
{
	if (Cur[0] == 0)
	{
		if (s.count(Cur[2]))
		{
			return;
		}
		else
		{
			s.insert(Cur[2]);
		}
	}

	if (s2.count(tuple<int, int, int>(Cur[0], Cur[1], Cur[2])))
	{
		return;
	}
	else
	{
		s2.insert(tuple<int, int, int>(Cur[0], Cur[1], Cur[2]));
	}

	// 0번 물통에서 물을 옮기는 경우
	if (Cur[0] != 0)
	{
		// 1번으로
		if (Cur[1] < v[1])
		{
			int diff = v[1] - Cur[1];

			// 0번 물통의 물을 다 부을 수 없다.
			if (diff < Cur[0])
			{
				//Cur[0] = Cur[0] - diff;
				//Cur[1] = v[1];
				dfs({ Cur[0] - diff ,v[1],Cur[2] });
			}
			// 0번 물통의 물을 1번 물통으로 다 부을 수 있다.
			else
			{
				//Cur[0] = 0;
				//Cur[1] = Cur[0];
				dfs({ 0, Cur[0] + Cur[1], Cur[2] });
			}
		}
		// 2번으로
		if (Cur[2] < v[2])
		{
			int diff = v[2] - Cur[2];

			// 0번 물통의 물을 다 부을 수 없다.
			if (diff < Cur[0])
			{
				//Cur[0] = Cur[0] - diff;
				//Cur[2] = v[2];
				dfs({ Cur[0] - diff ,Cur[1],v[2] });
			}
			// 0번 물통의 물을 2번 물통으로 다 부을 수 있다.
			else
			{
				//Cur[0] = 0;
				//Cur[2] = Cur[0];
				dfs({ 0,Cur[1], Cur[0] + Cur[2] });
			}
		}
	}

	// 1번 물통에서 물을 옮기는 경우
	if (Cur[1] != 0)
	{
		// 0번으로
		if (Cur[0] < v[0])
		{
			int diff = v[0] - Cur[0];

			// 1번 물통의 물을 다 부을 수 없다.
			if (diff < Cur[1])
			{
				//Cur[1] = Cur[1] - diff;
				//Cur[0] = v[0];
				dfs({ v[0] ,Cur[1] - diff,Cur[2] });
			}
			// 1번 물통의 물을 0번 물통으로 다 부을 수 있다.
			else
			{
				//Cur[1] = 0;
				//Cur[0] = Cur[1];
				dfs({ Cur[0] + Cur[1], 0 , Cur[2] });
			}
		}
		// 2번으로
		if (Cur[2] < v[2])
		{
			int diff = v[2] - Cur[2];

			// 1번 물통의 물을 다 부을 수 없다.
			if (diff < Cur[1])
			{
				//Cur[1] = Cur[1] - diff;
				//Cur[2] = v[2];
				dfs({ Cur[0] ,Cur[1] - diff,v[2] });
			}
			// 1번 물통의 물을 2번 물통으로 다 부을 수 있다.
			else
			{
				//Cur[1] = 0;
				//Cur[2] = Cur[1];
				dfs({ Cur[0], 0 , Cur[1] + Cur[2] });
			}
		}
	}

	// 2번 물통에서 물을 옮기는 경우
	if (Cur[2] != 0)
	{
		// 0번으로
		if (Cur[0] < v[0])
		{
			int diff = v[0] - Cur[0];

			// 2번 물통의 물을 다 부을 수 없다.
			if (diff < Cur[2])
			{
				//Cur[2] = Cur[2] - diff;
				//Cur[0] = v[0];
				dfs({ v[0] ,Cur[1] ,Cur[2] - diff });
			}
			// 2번 물통의 물을 0번 물통으로 다 부을 수 있다.
			else
			{
				//Cur[2] = 0;
				//Cur[0] = Cur[2];
				dfs({ Cur[0] + Cur[2], Cur[1] , 0 });
			}
		}
		// 1번으로
		if (Cur[1] < v[1])
		{
			int diff = v[1] - Cur[1];

			// 2번 물통의 물을 다 부을 수 없다.
			if (diff < Cur[2])
			{
				//Cur[2] = Cur[2] - diff;
				//Cur[1] = v[1];
				dfs({ Cur[0] ,v[1],Cur[2] - diff });
			}
			// 2번 물통의 물을 1번 물통으로 다 부을 수 있다.
			else
			{
				//Cur[2] = 0;
				//Cur[1] = Cur[2];
				dfs({ Cur[0], Cur[1] + Cur[2] , 0 });
			}
		}
	}
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	v.resize(3);

	for (int i = 0; i < 3; ++i)
	{
		cin >> v[i];
	}

	vector<int> Cur = { 0, 0, v[2] };

	dfs(Cur);


	set<int>::iterator iter = s.begin();

	for (; iter != s.end(); ++iter)
	{
		cout << *iter << " ";
	}

	return 0;
}