#include <bits/stdc++.h>
#include <unordered_map>


using namespace std;

typedef long long ll;

int N, M;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	// 시간 ,위치
	queue<pair<int, int>> q;
	unordered_map<int, bool> m;

	q.push({ 0,N });

	while (!q.empty())
	{
		int time = q.front().first;
		int Cur = q.front().second;
		q.pop();

		if (m[Cur] == false)
			m[Cur] = true;
		else
			continue;

		if (Cur < 0 || Cur>100000)
			continue;

		if (Cur == M)
		{
			cout << time;
			return 0;
		}

		q.push({ time + 1,Cur - 1 });
		q.push({ time + 1,Cur + 1 });
		q.push({ time + 1,Cur * 2 });
	}


	return 0;
}