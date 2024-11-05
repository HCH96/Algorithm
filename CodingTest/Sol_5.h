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

    // 가능한 인덱스
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

            // left의 char가 필요 없는 문자인 경우
            if (s2.find(leftChar) == s2.end())
            {
                --count[leftChar];
                ++left;
                continue;
            }

            // 필요한 문자들일 경우

            // 윈도우를 줄이면 문자열 완성이 안되는 경우 문자열 저장
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
