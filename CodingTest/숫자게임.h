#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int IdxA = 0;
    int IdxB = 0;

    while (IdxA < A.size() && IdxB < B.size())
    {
        while (IdxB < B.size() && A[IdxA] >= B[IdxB])
        {
            ++IdxB;
        }

        if (IdxB < B.size())
        {
            ++answer;
            ++IdxA;
            ++IdxB;
        }
        else
        {
            break;
        }
    }

    return answer;
}