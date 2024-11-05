//#include <bits/stdc++.h>
//
//using namespace std;
//
//string ltrim(const string&);
//string rtrim(const string&);
//
//
//
///*
// * Complete the 'sumVips' function below.
// *
// * The function is expected to return a LONG_INTEGER.
// * The function accepts following parameters:
// *  1. INTEGER_ARRAY score
// *  2. INTEGER guilder_count
// *  3. INTEGER k
// */
//
//long sumVips(vector<int> score, int guilder_count, int k) {
//
//    long ans = 0;
//
//    int left = 0;
//    int right = 0;
//
//    for (int i = 0; i < guilder_count; ++i)
//    {
//        vector<int>::iterator iter = score.begin();
//
//        if (k <= score.size())
//        {
//            auto leftMax = max_element(score.begin() + left, score.begin() + left + k);
//            auto rightMax = max_element(score.begin() + score.size() - k - right, score.end() - right);
//
//            if (*leftMax >= *rightMax)
//            {
//                iter = leftMax;
//                swap(score[left], *iter);
//                ++left;
//            }
//            else
//            {
//                iter = rightMax;
//                swap(score[right], *iter);
//                --right;
//            }
//        }
//        else
//        {
//            iter = max_element(score.begin(), score.end());
//            swap(score[left], *iter);
//            ++left;
//        }
//    }
//
//    for (int i = 0; i < left; ++i)
//    {
//        ans += score[i];
//    }
//
//    for (int i = 0; i < right; ++i)
//    {
//        ans += score[score.size() - i -1];
//    }
//
//    return ans;
//}
