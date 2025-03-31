#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <deque>


using namespace std;

int T, M, N, K, R, C, V, Ans;
int diff[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;

	vector<int> visited(100001, -1);
	deque<int> dq;
	visited[N] = 0;
	dq.push_back(N);

	while (!dq.empty())
	{
		int Cur = dq.front();
		dq.pop_front();

		if (Cur * 2 >= 0 && Cur * 2 < 100001 && visited[Cur*2] == -1)
		{
			visited[Cur * 2] = visited[Cur];
			dq.push_front(Cur * 2);
		}



		if (Cur - 1 >= 0 && Cur - 1 < 100001 && visited[Cur - 1] == -1)
		{
			visited[Cur - 1] = visited[Cur] + 1;
			dq.push_back(Cur - 1);
		}

		if (Cur + 1 >= 0 && Cur + 1 < 100001 && visited[Cur + 1] == -1)
		{
			visited[Cur + 1] = visited[Cur] + 1;
			dq.push_back(Cur + 1);
		}
	}

	cout << visited[K] << endl;


	return 0;
}