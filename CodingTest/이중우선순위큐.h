#include <string>
#include <vector>

#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    multiset<int> s;

    for (int i = 0; i < operations.size(); ++i)
    {
        string Oper = operations[i].substr(0, 1);
        int Num = stoi(operations[i].substr(2));

        if (Oper[0] == 'I')
        {
            s.insert(Num);
        }
        else
        {
            
            if (Num == 1)
            {
                if (s.size() != 0)
                {
                    s.erase(--s.end());
                }
            }
            else
            {
                if (s.size() != 0)
                {
                    s.erase(s.begin());
                }
            }
        }
    }

    if (s.size() == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(*s.begin());
        answer.push_back(*(--s.end()));
    }

    return answer;
}