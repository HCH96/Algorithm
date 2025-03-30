#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>


using namespace std;

int T, M, N, K, R, C, V, Ans;
int diff[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;

	int Answer = -1;

	vector<bool> visited(100001,false);
	queue<pair<int, int>> q;

	visited[N] = true;
	q.push({ N,0 });

	while (!q.empty())
	{
		int CurPos = q.front().first;
		int CurTime = q.front().second;
		q.pop();

		if (CurPos == K)
		{
			Answer = CurTime;
			break;
		}

		int NextPos[3] = { CurPos - 1, CurPos + 1, CurPos * 2 };

		for (int i = 0; i < 3; ++i)
		{
			int Next = NextPos[i];

			if (Next < 0 || Next >100000 || visited[Next] == true)
			{
				continue;
			}

			visited[Next] = true;
			q.push({ Next ,CurTime + 1 });

		}
	}

	cout << Answer;



	return 0;
}