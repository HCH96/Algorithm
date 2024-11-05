#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, int> Totalplay;
    unordered_map < string, vector<pair<int, int>>> m; // ¿Â∏£ , {«√∑π¿Ã »Ωºˆ, ¿Œµ¶Ω∫}

    for (int i = 0; i < genres.size(); ++i)
    {
        string CurGenre = genres[i];
        int playCnt = plays[i];

        Totalplay[CurGenre] += playCnt;
        m[CurGenre].push_back({ playCnt,i });
    }

    vector<pair<string, int>> vTotalPlay(Totalplay.begin(), Totalplay.end());

    sort(vTotalPlay.begin(), vTotalPlay.end(), [](const pair<string, int>& A, const pair<string, int>& B) {
        return A.second > B.second;
        });


    for (int i = 0; i < vTotalPlay.size(); ++i)
    {
        vector<pair<int, int>> CurGenreMusic = m[vTotalPlay[i].first];

        sort(CurGenreMusic.begin(), CurGenreMusic.end(), [](const pair<int, int>& A, const pair<int, int>& B) {
            return A.first > B.first;
            });

        int idx = 0;

        while (idx < CurGenreMusic.size() && idx <2)
        {
            answer.push_back(CurGenreMusic[idx].second);
            ++idx;
        }
    }

    return answer;
}