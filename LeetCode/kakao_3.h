#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    list<string> l;
    unordered_map<string, bool> m;

    for (int i = 0; i < cities.size(); ++i)
    {
        string CurCity = cities[i];

        transform(CurCity.begin(), CurCity.end(), CurCity.begin(), ::toupper);

        if (m[CurCity])
        {
            // hit
            l.erase(find(l.begin(), l.end(), CurCity));
            l.push_back(CurCity);
            answer += 1;
        }
        else
        {
            // miss
            answer += 5;

            if (!l.empty() && l.size() >= cacheSize)
            {
                m[l.front()] = false;
                l.pop_front();
            }

            if (l.size() < cacheSize)
            {
                l.push_back(CurCity);
                m[CurCity] = true;
            }
        }
    }

    return answer;
}