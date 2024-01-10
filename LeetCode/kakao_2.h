#pragma once

#include <string>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;

    string tmp;
    int PrevNum = 0;
    int i = 0;

    while (i < dartResult.size())
    {
        while (isdigit(dartResult[i]))
        {
            tmp.append(1, dartResult[i++]);
        }

        int Cur = stoi(tmp);

        switch (dartResult[i])
        {
        case 'S':
            break;
        case 'D':
            Cur = pow(Cur, 2);
            break;
        case 'T':
            Cur = pow(Cur, 3);
            break;
        default:
            break;
        }
        ++i;

        switch (dartResult[i])
        {
        case '*':
        {
            answer += PrevNum;
            Cur *= 2;
            ++i;
        }
        break;
        case '#':
        {
            Cur *= -1;
            ++i;
        }
        break;
        default:
            break;
        }

        answer += Cur;
        PrevNum = Cur;
        tmp.clear();
    }

    return answer;
}