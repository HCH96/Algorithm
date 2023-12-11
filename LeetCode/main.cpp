#include "pch.h"
#include <iostream>

#include "Solution_332.h"




int main()
{
	// tickets =	[["JFK", "SFO"], ["JFK", "ATL"], ["SFO", "ATL"], ["ATL", "JFK"], ["ATL", "SFO"]]

	vector<vector<string>> tickets = {{"JFK","SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"},{"ATL", "JFK"},{"ATL", "SFO"} };

	Solution s;

	s.findItinerary(tickets);

	return 0;
}