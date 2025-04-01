#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, string> &a, const pair<int, string> &b)
{
    return a.first < b.first;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, string>> v;
    for (int i = 0; i < n; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        v.push_back({age, name});
    }

    stable_sort(v.begin(), v.end(), compare);

    for(int i=0; i<n; i++){
        cout<< v[i].first  << " " << v[i].second << "\n";
    }
}