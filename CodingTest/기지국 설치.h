#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int range = 2 * w + 1;
    
    int left = 0;
    int right = 0;

    for (int i = 0; i < stations.size(); ++i)
    {
        right = stations[i] - w;

        int length = right - left;
        
        if (length > 0)
        {
            answer += length / range;
            if (length % range > 0)
            {
                ++answer;
            }
        }

        left = stations[i] + w + 1;
    }


    right = n + 1;

    int length = right - left;

    if (length > 0)
    {
        answer += length / range;
        if (length % range > 0)
        {
            ++answer;
        }
    }

    return answer;
}