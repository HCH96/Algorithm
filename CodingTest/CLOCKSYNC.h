#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int C, ans;

bool IsComplete(vector<vector<int>>& clock)
{
	for (int i = 0; i < 16; ++i)
	{
		int row = i / 4;
		int col = i % 4;

		if (clock[row][col] != 0)
		{
			return false;
		}
	}

	return true;
}

void ProcTime(vector<vector<int>>& clock, const vector<int>& targets)
{
	for (int i = 0; i < targets.size(); ++i)
	{
		int row = targets[i] / 4;
		int col = targets[i] % 4;

		clock[row][col] = (clock[row][col] + 1) % 4;
	}
}

void Solution(const vector<vector<int>>& Switch, vector<vector<int>>& clock, int count, int depth)
{
	if (IsComplete(clock))
	{
		ans = min(ans, count);
		return;
	}

	if (depth > 9)
		return;

	for (int i = 0; i < 4; ++i)
	{
		Solution(Switch, clock, count + i, depth + 1);
		ProcTime(clock, Switch[depth]);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> C;

	vector<vector<int>> Switch(10, vector<int>());
	Switch[0] = { 0,1,2 };
	Switch[1] = { 3,7,9,11 };
	Switch[2] = { 4,10,14,15 };
	Switch[3] = { 0,4,5,6,7 };
	Switch[4] = { 6,7,8,10,12 };
	Switch[5] = { 0,2,14,15 };
	Switch[6] = { 3,14,15 };
	Switch[7] = { 4,5,7,14,15 };
	Switch[8] = { 1,2,3,4,5 };
	Switch[9] = { 3,4,5,9,13 };


	while (C--)
	{
		ans = INT_MAX;

		vector<vector<int>> clock(4, vector<int>(4, 0));

		for (int i = 0; i < 16; ++i)
		{
			int row = i / 4;
			int col = i % 4;

			cin >> clock[row][col];
			clock[row][col] = (clock[row][col] / 3) % 4;
		}

		Solution(Switch, clock, 0, 0);

		if (ans == INT_MAX)
			ans = -1;

		cout << ans << "\n";
	}

	return 0;
}
