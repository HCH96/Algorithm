#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);



int programmerStrings(string s) {

    string target = "programmer";
    unordered_map<char, int> m;
    set<char> s2;

    for (int i = 0; i < target.size(); ++i)
    {
        s2.insert(target[i]);
        ++m[target[i]];
    }

    // ������ �ε���
    vector<pair<int, int>> idx;
    unordered_map<char, int> count;

    int left = 0;
    int right = 0;

    // p,r,o,g,a,m,e;
    int RestCnt = 7;

    while (right < s.size())
    {
        char Cur = s[right];
        ++count[Cur];

        if (s2.find(Cur) != s2.end() && m[Cur] == count[Cur])
        {
            --RestCnt;
        }

        while (RestCnt == 0 && left <= right)
        {
            char leftChar = s[left];

            // left�� char�� �ʿ� ���� ������ ���
            if (s2.find(leftChar) == s2.end())
            {
                --count[leftChar];
                ++left;
                continue;
            }

            // �ʿ��� ���ڵ��� ���

            // �����츦 ���̸� ���ڿ� �ϼ��� �ȵǴ� ��� ���ڿ� ����
            if (count[leftChar] - 1 < m[leftChar])
            {
                idx.push_back({ left,right });
                ++RestCnt;
            }

            --count[leftChar];
            ++left;
        }
        ++right;
    }

    int ans = idx[idx.size() - 1].first - idx[0].second - 1;

    return ans;
}

//
//int main()
//{
//    string ss = "progxrammerrxproxgrammer";
//    programmerStrings(ss);
//
//    return 0;
//}
