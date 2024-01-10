#pragma once

#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

string trans(string& str)
{
    string tmp = "";

    int i = 0;

    while (i < str.size())
    {
        if (isalpha(str[i]))
            tmp += toupper(str[i]);
        else
            tmp += str[i];

        ++i;
    }

    return tmp;
}


int solution(string str1, string str2) {
    int answer = 0;

    str1 = trans(str1);
    str2 = trans(str2);

    unordered_map<string, int> m1;
    unordered_map<string, int> m2;

    set<string> s;

    for (int i = 0; i < str1.size() - 1; ++i)
    {
        if (isalpha(str1[i]) && isalpha(str1[i + 1]))
        {
            string tmp = str1.substr(i, 2);
            s.insert(tmp);
            ++m1[tmp];
        }
    }

    for (int i = 0; i < str2.size() - 1; ++i)
    {
        if (isalpha(str2[i]) && isalpha(str2[i + 1]))
        {
            string tmp = str2.substr(i, 2);
            s.insert(tmp);
            ++m2[tmp];
        }
    }

    set<string>::iterator iter = s.begin();

    float gyo = 0.f;
    float hap = 0.f;

    while (iter != s.end())
    {
        hap += max(m1[*iter], m2[*iter]);
        gyo += min(m1[*iter], m2[*iter]);
        ++iter;
    }

    if (hap == 0)
    {
        answer = 65536;
    }
    else
    {
        answer = int(gyo / hap * 65536);
    }
    return answer;
}