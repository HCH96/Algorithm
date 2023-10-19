#pragma once

#include "pch.h"


class Solution_121 {
public:
    int maxProfit(vector<int>& a) {

        int ans = -1;
        int max_price = -1;

        for (int i = a.size()-1; i >= 0; --i)
        {
            if (a[i] > max_price)
            {
                max_price = a[i];
            }

            if (max_price - a[i] > ans)
                ans = max_price - a[i];
        }

        int min_price = 99999;
        for (int i = 0; i < a.size(); ++i)
        {
            if (a[i] < min_price)
                min_price = a[i];

            if (ans < a[i] - min_price)
                ans = a[i] - min_price;

        }


        return ans;
    }
};