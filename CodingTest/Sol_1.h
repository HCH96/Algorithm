#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);



/*
 * Complete the 'Moves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int Moves(vector<int> arr) {

    int ans = 0;
    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        while (left < right && arr[left] % 2 != 1)
        {
            ++left;
        }

        while (left < right && arr[right] % 2 != 0)
        {
            --right;
        }

        if (left < right)
        {
            swap(arr[left++], arr[right--]);
            ++ans;
        }
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    int result = Moves(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
