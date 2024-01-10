#pragma once

#include <string>
#include <vector>
#include <queue>


using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    priority_queue<int, vector<int>, greater<int>> pq;
    int last = 540;

    for (int i = 0; i < timetable.size(); ++i)
    {
        pq.push(stoi(timetable[i].substr(0, 2)) * 60 + stoi(timetable[i].substr(3, 2)));
    }

    for (int i = 0; i < n; ++i)
    {
        int StartTime = 540 + i * t;
        int Cur = 0;

        while (!pq.empty() && pq.top() <= StartTime && Cur < m)
        {
            last = pq.top();
            pq.pop();
            ++Cur;
        }

        // 버스를 다 안탐
        if (Cur < m)
        {
            last = StartTime + 1;
        }
    }

    last -= 1;

    answer += to_string(last / 60);

    if (answer.size() == 1)
    {
        answer.insert(answer.begin(), '0');
    }

    answer += ':';

    if (10 > last % 60)
    {
        answer += '0';   
    }

    answer += to_string(last % 60);

    return answer;
}