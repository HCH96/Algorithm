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

	// 0�� ���뿡�� ���� �ű�� ���
	if (Cur[0] != 0)
	{
		// 1������
		if (Cur[1] < v[1])
		{
			int diff = v[1] - Cur[1];

			// 0�� ������ ���� �� ���� �� ����.
			if (diff < Cur[0])
			{
				//Cur[0] = Cur[0] - diff;
				//Cur[1] = v[1];
				dfs({ Cur[0] - diff ,v[1],Cur[2] });
			}
			// 0�� ������ ���� 1�� �������� �� ���� �� �ִ�.
			else
			{
				//Cur[0] = 0;
				//Cur[1] = Cur[0];
				dfs({ 0, Cur[0] + Cur[1], Cur[2] });
			}
		}
		// 2������
		if (Cur[2] < v[2])
		{
			int diff = v[2] - Cur[2];

			// 0�� ������ ���� �� ���� �� ����.
			if (diff < Cur[0])
			{
				//Cur[0] = Cur[0] - diff;
				//Cur[2] = v[2];
				dfs({ Cur[0] - diff ,Cur[1],v[2] });
			}
			// 0�� ������ ���� 2�� �������� �� ���� �� �ִ�.
			else
			{
				//Cur[0] = 0;
				//Cur[2] = Cur[0];
				dfs({ 0,Cur[1], Cur[0] + Cur[2] });
			}
		}
	}

	// 1�� ���뿡�� ���� �ű�� ���
	if (Cur[1] != 0)
	{
		// 0������
		if (Cur[0] < v[0])
		{
			int diff = v[0] - Cur[0];

			// 1�� ������ ���� �� ���� �� ����.
			if (diff < Cur[1])
			{
				//Cur[1] = Cur[1] - diff;
				//Cur[0] = v[0];
				dfs({ v[0] ,Cur[1] - diff,Cur[2] });
			}
			// 1�� ������ ���� 0�� �������� �� ���� �� �ִ�.
			else
			{
				//Cur[1] = 0;
				//Cur[0] = Cur[1];
				dfs({ Cur[0] + Cur[1], 0 , Cur[2] });
			}
		}
		// 2������
		if (Cur[2] < v[2])
		{
			int diff = v[2] - Cur[2];

			// 1�� ������ ���� �� ���� �� ����.
			if (diff < Cur[1])
			{
				//Cur[1] = Cur[1] - diff;
				//Cur[2] = v[2];
				dfs({ Cur[0] ,Cur[1] - diff,v[2] });
			}
			// 1�� ������ ���� 2�� �������� �� ���� �� �ִ�.
			else
			{
				//Cur[1] = 0;
				//Cur[2] = Cur[1];
				dfs({ Cur[0], 0 , Cur[1] + Cur[2] });
			}
		}
	}

	// 2�� ���뿡�� ���� �ű�� ���
	if (Cur[2] != 0)
	{
		// 0������
		if (Cur[0] < v[0])
		{
			int diff = v[0] - Cur[0];

			// 2�� ������ ���� �� ���� �� ����.
			if (diff < Cur[2])
			{
				//Cur[2] = Cur[2] - diff;
				//Cur[0] = v[0];
				dfs({ v[0] ,Cur[1] ,Cur[2] - diff });
			}
			// 2�� ������ ���� 0�� �������� �� ���� �� �ִ�.
			else
			{
				//Cur[2] = 0;
				//Cur[0] = Cur[2];
				dfs({ Cur[0] + Cur[2], Cur[1] , 0 });
			}
		}
		// 1������
		if (Cur[1] < v[1])
		{
			int diff = v[1] - Cur[1];

			// 2�� ������ ���� �� ���� �� ����.
			if (diff < Cur[2])
			{
				//Cur[2] = Cur[2] - diff;
				//Cur[1] = v[1];
				dfs({ Cur[0] ,v[1],Cur[2] - diff });
			}
			// 2�� ������ ���� 1�� �������� �� ���� �� �ִ�.
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