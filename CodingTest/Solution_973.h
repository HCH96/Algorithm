#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        sort(points.begin(), points.end(), [](const vector<int>& A, const vector<int>& B) {

            int DistA = A[0] * A[0] + A[1] * A[1];
            int DistB = B[0] * B[0] + B[1] * B[1];

            return DistA < DistB;
            });


        vector<vector<int>> ans(points.begin(), points.begin() + k);

        return ans;
    }
};