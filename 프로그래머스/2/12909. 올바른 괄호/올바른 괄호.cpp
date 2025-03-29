#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int cnt =0;
    
    for(auto it: s)
    {
        if(it == '(')
        {
            ++cnt;
        }
        else
        {
            --cnt;
            if(cnt <0)
            {
                answer = false;
                break;
            }
        }
    }
    
    if(cnt !=0)
        answer = false;
    
    

    return answer;
}