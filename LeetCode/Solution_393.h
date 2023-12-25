#pragma once
#include "pch.h"

class Solution {
public:
    bool validUtf8(vector<int>& data) {

        if (data.size() == 0)
            return false;

        if ((data[0] & 0b10000000) == 0b00000000)
        {
            if (data.size() >= 1)
                return true;
            else
                return false;
        }

        if ((data[0] & 0b11100000) == 0b11000000)
        {
            if (data.size() >= 2 && (data[1] & 0b11000000) == 0b10000000)
                return true;
            else
                return false;
        }

        if ((data[0] & 0b11110000) == 0b11100000)
        {
            if (data.size() >= 3 && (data[1] & 0b11000000) == 0b10000000 && (data[2] & 0b11000000) == 0b10000000)
                return true;
            else
                return false;
        }

        if ((data[0] & 0b11111000) == 0b11110000)
        {
            if (data.size() >= 4 && (data[1] & 0b11000000) == 0b10000000 && (data[2] & 0b11000000) == 0b10000000 && (data[3] & 0b11000000) == 0b10000000)
                return true;
            else
                return false;
        }

        return false;
    }
};