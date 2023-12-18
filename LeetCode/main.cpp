#include "pch.h"
#include <iostream>

#include "Solution_332.h"




#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

struct cmp
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
};

int main() {
    priority_queue<pair<int,int>, vector<pair<int, int>>, cmp> pq;

    pq.push({ 1,5 });
    pq.push({ 2,2 });
    pq.push({ 3,1 });


    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        cout << "(" << top.first << ", " << top.second << ")";
    }

    return 0;
}