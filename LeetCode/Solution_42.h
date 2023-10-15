#pragma once

#include "global.h"


class Solution_42 {
public:
    int trap(vector<int>& height) {
        
        int ans = 0;

        int left = 0;
        int right = height.size() - 1;

        int max_left = 0, max_right = 0;



        while (left <= right)
        {
            if (height[left] > max_left)
            {
                max_left = height[left];
            }

            if (height[right] > max_right)
            {
                max_right = height[right];
            }

            if (max_left < max_right)
            {
                ans += max_left - height[left];
                left++;
            }
            else
            {
                ans += max_right - height[right];
                right--;
            }
        }

        return ans;

    }
};
