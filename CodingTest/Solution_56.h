#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {

		sort(intervals.begin(), intervals.end(),
			[](const vector<int>& First, const vector<int>& Second)
			{
				if (First[0] == Second[0])
					return First[1] > Second[1];
				return First[0] < Second[0];
			});

		vector<vector<int>>::iterator iter = intervals.begin();

		for (; iter != intervals.end(); ++iter)
		{
			auto next = iter + 1;

			while (next != intervals.end())
			{
				if ((*iter)[1] < (*next)[0])
					break;

				if ((*iter)[1] < (*next)[1])
				{
					(*iter)[1] = (*next)[1];
				}

				next = intervals.erase(next);
			}
		}

		return intervals;
	}
};