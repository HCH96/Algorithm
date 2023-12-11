#pragma once

#include "pch.h"

vector<string> ans;
bool flag = false;

void DFS(const string& Cur, unordered_map<string, vector<pair<string, bool>>>& m, int ticketSize, vector<string>& tmp)
{
    if(flag == true)
    {
        return;
    }

    // 현재 위치 기록
    tmp.push_back(Cur);

    if (tmp.size() == ticketSize + 1 && flag == false)
    {
        ans = tmp;
        flag = true;
        return;
    }

    vector<pair<string, bool>>& next = m[Cur];


    for (int i = 0; i < next.size(); ++i)
    {
        if (next[i].second == false && flag == false)
        {
            next[i].second = true;
            DFS(next[i].first, m, ticketSize, tmp);
            next[i].second = false;
        }

    }

    // 현재 위치 제거
    tmp.pop_back();

}


class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 전역변수 초기값 세팅
        flag = false;
        ans.clear();

        // 정렬
        sort(tickets.begin(), tickets.end(), [](vector<string>& first, vector<string>& second)->bool
            {
                return first[1] < second[1];
            });

        //for (int i = 0; i < tickets.size(); ++i)
        //{
        //    cout << tickets[i][0] << " " << tickets[i][1] << endl;
        //}


        // Key = From, Value = { To, Uesd}
        unordered_map<string, vector<pair<string,bool>>> m;


        for (int i = 0; i < tickets.size(); ++i)
        {
            string first = tickets[i][0];
            string second = tickets[i][1];

            m[first].push_back({ second,false });
        }

        vector<string> tmp;


        DFS("JFK", m, tickets.size(), tmp);

        return ans;
    }
};
