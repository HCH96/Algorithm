#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int N, K;
bool visited[100001];


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	int ans = -1;
	int cnt = 0;

	// 시간, 위치
	queue<pair<int, int>> q;

	q.push({ 0,N });
	visited[N] = true;

	while (!q.empty())
	{
		int Time = q.front().first;
		int Pos = q.front().second;
		q.pop();

		visited[Pos] = true;

		if (ans != -1 && Pos == K && Time == ans)
		{
			++cnt;
			continue;
		}

		if (ans == -1 && Pos == K)
		{
			++cnt;
			ans = Time;
		}

		// -1
		if (Pos - 1 >= 0 && visited[Pos - 1] == false)
		{
			q.push({ Time + 1,Pos - 1 });
		}

		// +1
		if (Pos + 1 <= 100000 && visited[Pos + 1] == false)
		{
			q.push({ Time + 1,Pos + 1 });
		}

		// *1
		if (Pos * 2 <= 100000 && visited[Pos * 2] == false)
		{
			q.push({ Time + 1,Pos * 2 });
		}
	}

	cout << ans << endl << cnt;

	return 0;
}

