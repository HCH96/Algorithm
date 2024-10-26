#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    
    long long answer = 0;

    priority_queue<long long> pq;

    for (int i = 0; i < works.size(); ++i)
    {
        pq.push(works[i]);
    }

    while (!pq.empty() && n > 0)
    {
        long long Cur = pq.top();
        pq.pop();

        if (Cur - 1 > 0)
        {
            pq.push(Cur - 1);
        }
        
        --n;
    }

    while (!pq.empty())
    {
        long long Cur = pq.top();
        pq.pop();

        answer += pow(Cur, 2);

    }

    return answer;
}