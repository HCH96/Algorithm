#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C;
int N, L;


int SOlution()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> C;

    while (C--)
    {
        double ans = 1000000.;

        cin >> N >> L;

        vector<double> v(N, 0);
        for (int i = 0; i < N; ++i)
        {
            cin >> v[i];
        }

        for (int i = L; i <= N; ++i)
        {
            double Sum = 0.;
            double WindowSum = 0.;

            for (int j = 0; j < i; ++j)
            {
                WindowSum += v[j];
            }

            Sum = WindowSum;

            for (int idx = i; idx < N; ++idx)
            {
                WindowSum = WindowSum + v[idx] - v[idx - i];

                Sum = min(Sum, WindowSum);
            }

            ans = min(ans, Sum / double(i));
        }

        printf("%.12f\n", ans);
    }


    return 0;
}
