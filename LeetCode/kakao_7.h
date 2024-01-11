#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int solution(vector<string> lines) {
    int answer = 0;

    // start, end
    vector<pair<int, int>> table;
    multiset<pair<int, int>> s;

    for (int i = 0; i < lines.size(); ++i)
    {
        // "2016-09-15 01:00:04.002 2.0s"
        lines[i].pop_back();

        string hour = lines[i].substr(11, 2);
        string min = lines[i].substr(14, 2);
        string sec = lines[i].substr(17, 2);
        string ms = lines[i].substr(20, 3);
        string time = lines[i].substr(24);

        // "2016-09-15 01:00:04.002 2.0s"
        // 01:00:02.003 ~ 01:00:04.002

        int endTime = stoi(hour) * 3600 * 1000 + stoi(min) * 60 * 1000 + stoi(sec) * 1000 + stoi(ms);
        int startTime = endTime - stof(time) * 1000 + 1;

        table.push_back({ startTime, endTime });
    }

    int i = 0;
    while (i < table.size())
    {
        s.insert(table[i]);

        int endTime = table[i].second;

        set<pair<int, int>>::iterator iter = s.begin();
        for (; iter != s.end();)
        {
            if (iter->second < endTime)
            {
                iter = s.erase(iter);
            }
            else
            {
                ++iter;
            }
        }

        int cnt = 0;

        for (int j = i; j < table.size(); ++j)
        {
            if (table[j].first < endTime + 1000)
                ++cnt;
        }

        answer = max(answer, cnt);

        ++i;
    }


    return answer;
}