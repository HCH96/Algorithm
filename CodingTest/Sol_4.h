#include <bits/stdc++.h>

using namespace std;

//
//string ltrim(const string&);
//string rtrim(const string&);
//
//
//
///*
// * Complete the 'minDeletions' function below.
// *
// * The function is expected to return an INTEGER.
// * The function accepts INTEGER_ARRAY arr as parameter.
// */
//

int minDeletions(vector<int> arr) {
    
    vector<int> v;

    for (int i = 0; i < arr.size(); ++i)
    {
        int target = arr[i];

        vector<int>::iterator iter = lower_bound(v.begin(), v.end(), target);

        if (iter == v.end())
        {
            v.push_back(target);
        }
        else
        {
            *iter = target;
        }
    }

    int size = v.size();

    int ans;

    if (arr.size() == size)
    {
        ans = 0;
    }
    else
    {
        ans = arr.size() - size - 1;
    }

    return ans;
}
//
//int main()
//{
//    ofstream fout(getenv("OUTPUT_PATH"));
//
//    string arr_count_temp;
//    getline(cin, arr_count_temp);
//
//    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));
//
//    vector<int> arr(arr_count);
//
//    for (int i = 0; i < arr_count; i++) {
//        string arr_item_temp;
//        getline(cin, arr_item_temp);
//
//        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));
//
//        arr[i] = arr_item;
//    }
//
//    int result = minDeletions(arr);
//
//    fout << result << "\n";
//
//    fout.close();
//
//    return 0;
//}
//
//string ltrim(const string& str) {
//    string s(str);
//
//    s.erase(
//        s.begin(),
//        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
//    );
//
//    return s;
//}
//
//string rtrim(const string& str) {
//    string s(str);
//
//    s.erase(
//        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
//        s.end()
//    );
//
//    return s;
//}
