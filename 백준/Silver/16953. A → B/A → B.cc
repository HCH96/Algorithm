#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, M;

int main() {

	cin >> N >> M;

	queue<pair<int, int>> q;
	q.push({ M,1 });

	while (!q.empty())
	{
		int CurNum = q.front().first;
		int CurCnt = q.front().second;;
		q.pop();

		if (CurNum == N) 
		{
			cout << CurCnt << endl;
			return 0;
		}

		if (CurNum % 10 == 1)
		{
			q.push({ CurNum / 10, CurCnt + 1 });
		}

		if (CurNum % 2 == 0 && CurNum / 2 > 0)
		{
			q.push({ CurNum / 2, CurCnt + 1 });
		}
	}
	
	cout << -1 << endl;


	return 0;
}