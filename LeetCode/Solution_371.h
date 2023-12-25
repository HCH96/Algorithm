#pragma once
#include "pch.h"

class Solution {
public:
    int getSum(int a, int b) {

        bool carry = false;
        int ans = 0;
        int idx = 0;

        while (idx < 32)
        {
            int tmpa = a & 1;
            int tmpb = b & 1;

            if (carry)
            {
                // 0,1 / 1,0
                if (tmpa ^ tmpb)
                {
                    ans &= ~(1 << idx);
                    carry = true;
                }
                else
                {
                    // 1,1
                    if (tmpa)
                    {
                        ans |= 1 << idx;
                        carry = true;
                    }
                    // 0,0
                    else
                    {
                        ans |= 1 << idx;
                        carry = false;

                    }

                }
            }
            else
            {
                // 0,1 / 1,0
                if (tmpa ^ tmpb)
                {
                    ans |= 1 << idx;
                    carry = false;
                }
                else
                {
                    // 1,1
                    if (tmpa)
                    {
                        ans &= ~(1 << idx);
                        carry = true;
                    }
                    // 0,0
                    else
                    {
                        ans &= ~(1 << idx);
                        carry = false;

                    }
                }
            }

            a = a >> 1;
            b = b >> 1;
            ++idx;
        }

        return ans;

    }
};