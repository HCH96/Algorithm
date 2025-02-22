#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long

using namespace std;

int N;

int input[3];
int mindp[2][3];
int maxdp[2][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int a, b, c;
	cin >> a >> b >> c;

	mindp[1][0] = a;
	mindp[1][1] = b;
	mindp[1][2] = c;
	
	maxdp[1][0] = a;
	maxdp[1][1] = b;
	maxdp[1][2] = c;

	for (int i = 1; i < N; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		input[0] = a;
		input[1] = b;
		input[2] = c;

		  mindp[0][0] = mindp[1][0];
		  mindp[0][1] = mindp[1][1];
		  mindp[0][2] = mindp[1][2];

		mindp[1][0] = min(mindp[0][0] + input[0], mindp[0][1] + input[0]);
		mindp[1][1] = min(mindp[0][0] + input[1], mindp[0][1] + input[1]);
		mindp[1][1] = min(mindp[1][1], mindp[0][2] + input[1]);
		mindp[1][2] = min(mindp[0][2] + input[2], mindp[0][1] + input[2]);

		maxdp[0][0] = maxdp[1][0];
		maxdp[0][1] = maxdp[1][1];
		maxdp[0][2] = maxdp[1][2];

		maxdp[1][0] = max(maxdp[0][0] + input[0], maxdp[0][1] + input[0]);
		maxdp[1][1] = max(maxdp[0][0] + input[1], maxdp[0][1] + input[1]);
		maxdp[1][1] = max(maxdp[1][1], maxdp[0][2] + input[1]);
		maxdp[1][2] = max(maxdp[0][2] + input[2], maxdp[0][1] + input[2]);
	}

	int ansMax = 0;
	int ansMin = INT_MAX;

	for (int i = 0; i < 3; ++i)
	{
		ansMax = max(ansMax, maxdp[1][i]);
		ansMin = min(ansMin, mindp[1][i]);
	}

	cout << ansMax << " " << ansMin;

	return 0;
}
