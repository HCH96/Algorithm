#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <unordered_set>

using namespace std;

int N;
vector<vector<char>> v;

void Sol(int Row, int Col, int Size)
{
    if (Size == 1)
    {
        v[Row][Col] = '*';
        return;
    }

    int Half = Size / 2;

    Sol(Row, Col, Half);
    Sol(Row + Half, Col, Half);
    Sol(Row, Col + Half, Half);
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    int Size = 1 << N;
    
    v.resize(Size, vector<char>(Size, ' '));
    
    Sol(0, 0, Size);

    for (int i = 0; i < Size; ++i)
    {
        for (int j = 0; j < Size-i; ++j)
        {
            cout << v[i][j];
        }
        cout << endl;
    }

    return 0;
}
