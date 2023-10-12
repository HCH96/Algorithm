#pragma once

#include <string>
#include <ctype.h>

using namespace std;

class Solution_125
{
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            while (left < s.size() && !isalnum(s[left]))
            {
                ++left;
            }

            while (right >= 0 && !isalnum(s[right]))
            {
                --right;
            }

            if (left >= s.size() || right < 0)
                break;

            if (toupper(s[left++]) != toupper(s[right--]))
                return false;
        }

        return true;
    }
};