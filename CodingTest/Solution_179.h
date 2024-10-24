#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {

        vector<string> num;

        for (int i = 0; i < nums.size(); ++i)
        {
            num.push_back(to_string(nums[i]));
        }

        sort(num.begin(), num.end(), [](const string& A, const string& B) {
            return A + B > B + A;
            });
        
        string ans;

        for (int i = 0; i < num.size(); ++i)
        {
            ans.append(num[i]);
        }

        return ans;
    }
};