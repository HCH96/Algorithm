#pragma once
#include "pch.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int sumfuel = 0;

        for (int i = 0; i < gas.size(); ++i)
        {
            sumfuel += gas[i];
            sumfuel -= cost[i];
        }
        if (sumfuel < 0)
            return -1;


        int ans = 0;
        sumfuel = 0;

        for (int i = 0; i < gas.size(); ++i)
        {
            sumfuel = sumfuel + gas[i] - cost[i];

            if (sumfuel < 0)
            {
                ans = i + 1;
                sumfuel = 0;
            }
        }

        return ans;
    }
};