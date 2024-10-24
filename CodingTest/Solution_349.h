#include <iostream>
#include <vector>
#include <set>


using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        set<int> s2;

        vector<int> ans;

        for (int i = 0; i < nums1.size(); ++i)
        {
            s.insert(nums1[i]);
        }


        for (int i = 0; i < nums2.size(); ++i)
        {
            s2.insert(nums2[i]);
        }

        for (auto it : s2)
        {
            if (s.find(it) != s.end())
            {
                ans.push_back(it);
            }
        }

        return ans;
    }
};