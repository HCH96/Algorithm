#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> Num[8]{
    vector<char>{'a','b','c'},
    vector<char>{'d','e','f'},
    vector<char>{'g','h','i'},
    vector<char>{'j','k','l'},
    vector<char>{'m','n','o'},
    vector<char>{'p','q','r','s'},
    vector<char>{'t','u','v'},
    vector<char>{'w','x','y','z'},
};

class Solution {

private:
    vector<string> ans;
    vector<int> Input;

public:
    void DFS(string& CurString, int depth)
    {
        if (depth == Input.size())
        {
            ans.push_back(CurString);
            return;
        }

        for (int i = 0; i < Num[Input[depth]].size(); ++i)
        {
            CurString += Num[Input[depth]][i];
            DFS(CurString, depth + 1);
            CurString.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        ans.clear();
        Input.clear();

        if (digits.size() == 0)
            return ans;

        for (int i = 0; i < digits.size(); ++i)
        {
            int Number = digits[i] - '2';

            Input.push_back(Number);
        }

        string tmp = "";
        DFS(tmp, 0);

        return ans;
    }
};