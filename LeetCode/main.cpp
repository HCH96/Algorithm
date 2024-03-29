#include "pch.h"
#include <iostream>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    priority_queue<int,vector<int>,greater<int>> pq;
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

        // ������ �� ��Ž
        if (Cur < m)
        {
            last = StartTime + 1;
        }
    }

    return answer;
}


int main() {
    vector<string> cities = { "09:10", "09:09", "08:00" };
    

    solution(2,10,2,cities);

    return 0;
}

