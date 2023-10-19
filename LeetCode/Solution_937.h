#pragma once

#include "pch.h"

class Solution937
{
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [](const string& log1, const string& log2)->bool {

            string id1 = log1.substr(0,log1.find(" "));
            string file1 = log1.substr(log1.find(" ")+1);

            string id2 = log2.substr(0, log2.find(" "));
            string file2 = log2.substr(log2.find(" ") + 1);


            if (isdigit(file1[0]) && isdigit(file2[0]))
            {
                return false;
            }

            if (isalpha(file1[0]) != isalpha(file2[0]))
            {
                return isalpha(file1[0]);
            }

            if (file1 == file2)
            {
                return id1 < id2;
            }
            else
            {
                return file1 < file2;
            }

            });

        return logs;

    }
};

