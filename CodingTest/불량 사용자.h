#include <string>
#include <vector>
#include <set>

using namespace std;

bool IsPossible(const string& A, const string& B)
{
    if (A.size() != B.size())
        return false;

    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] != B[i] && B[i] != '*')
            return false;
    }

    return true;
}

void DFS(int depth, const vector<vector<int>>& candidate, set<set<int>>& s, set<int>& Cur)
{
    if (depth == candidate.size())
    {
        s.insert(Cur);
        return;
    }

    for (int i = 0; i < candidate[depth].size(); ++i)
    {
        if (Cur.find(candidate[depth][i]) != Cur.end())
        {
            continue;
        }

        Cur.insert(candidate[depth][i]);
        DFS(depth + 1, candidate, s, Cur);
        Cur.erase(candidate[depth][i]);
    }
}


int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    vector<vector<int>> candidate(banned_id.size(), vector<int>());
    
    for (int i = 0; i < banned_id.size(); ++i)
    {
        const string& BanId = banned_id[i];

        for (int j = 0; j < user_id.size(); ++j)
        {
            const string& CurString = user_id[j];
            if (IsPossible(CurString, BanId))
            {
                candidate[i].push_back(j);
            }
        }
    }

    set<set<int>> s;
    set<int> Cur;
    DFS(0, candidate, s, Cur);

    answer = s.size();

    return answer;
}