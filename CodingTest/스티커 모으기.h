#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;
    int size = sticker.size();

    if (size == 0)
    {
        return answer;
    }

    if (size == 1)
    {
        return sticker[0];
    }

    vector<int> dp1(size,0); // 첫번째 스티커를 뜯음
    vector<int> dp2(size,0); // 첫번째 스티커를 안뜯음

    dp1[0] = sticker[0];
    dp1[1] = max(dp1[0], sticker[1]);
    
    dp2[0] = 0;
    dp2[1] = max(dp2[0], sticker[1]);

    for (int i = 2; i < dp1.size() - 1; ++i)
    {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + sticker[i]);
    }

    for (int i = 2; i < dp2.size(); ++i)
    {
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + sticker[i]);
    }

    for (int i = 0; i < dp1.size(); ++i)
    {
        answer = max(answer, dp1[i]);
        answer = max(answer, dp2[i]);
    }

    return answer;
}