#pragma once

#include "pch.h"

class Solution_819 
{
public:
    string mostCommonWord(string paragraph, vector<string>& banned)
    {
        unordered_map<string, int> count;
        unordered_set<string> ban_list(banned.begin(), banned.end());

        int check = 0;

        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), [](char c) -> char {
            if (isalpha(c)) return tolower(c);
            else return ' ';
            });

        paragraph.append(" ");

        string ans = "";
        int max = 0;


        for (int i = 0; i < paragraph.length(); ++i)
        {
            if (paragraph[i] == ' ')
            {
                string target = paragraph.substr(check, i-check);
                if (target.length() == 0)
                {
                    check = i + 1;
                    continue;
                }

                if (ban_list.count(target))
                {
                    check = i + 1;
                    continue;
                }

                if (count[target] == 0)
                {
                    count[target] = 1;
                }
                else
                {
                    ++count[target];
                }

                if (count[target] > max)
                {
                    max = count[target];
                    ans = target;
                }

                check = i + 1;
            }
        }

        return ans;

    }
};