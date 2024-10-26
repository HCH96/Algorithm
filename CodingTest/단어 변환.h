#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    queue<pair<string, int>> q;
    vector<bool> visited(words.size(), false);

    q.push({ begin, 0 });

    while (!q.empty())
    {
        string Cur = q.front().first;
        int Step = q.front().second;
        q.pop();

        if (Cur == target)
        {
            answer = Step;
            break;
        }

        for (int i = 0; i < words.size(); ++i)
        {
            string Next = words[i];
            int diffCount = 0;

            for (int j = 0; j < Next.size(); ++j)
            {
                if (Next[j] != Cur[j])
                    ++diffCount;
            }

            if (diffCount == 1 && visited[i] == false)
            {
                visited[i] = true;
                q.push({ Next,Step + 1 });
            }
        }
    }

    return answer;
}