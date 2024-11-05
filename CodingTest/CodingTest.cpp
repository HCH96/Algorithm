#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

long sumVips(vector<int> score, int guilder_count, int k) {

    long ans = 0;

    int left = 0;
    int right = 0;

    for (int i = 0; i < guilder_count; ++i)
    {
        vector<int>::iterator iter = score.begin();

        if (k <= score.size())
        {
            auto leftMax = max_element(score.begin() + left, score.begin() + left + k);
            auto rightMax = max_element(score.begin() + score.size() - k - right, score.end() - right);

            if (*leftMax >= *rightMax)
            {
                iter = leftMax;
                swap(score[left], *iter);
                ++left;
            }
            else
            {
                iter = rightMax;
                swap(score[right], *iter);
                --right;
            }
        }
        else
        {
            iter = max_element(score.begin(), score.end());
            swap(score[left], *iter);
            ++left;
        }
    }

    for (int i = 0; i < left; ++i)
    {
        ans += score[i];
    }

    for (int i = 0; i < right; ++i)
    {
        ans += score[score.size() - i - 1];
    }

    return ans;
}

int main()
{
    vector<int> v = { 8,21,8,15,5,30,21 };
    sumVips(v,2,3);

    return 0;
}
