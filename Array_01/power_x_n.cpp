#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double optimal(double x, int n)
    {
        double ans = 1.0;
        long long A = labs(n);
        while (A > 0)
        {
            if (A % 2 == 0)
            {
                x = x * x;
                A /= 2;
            }
            else
            {
                ans *= x;
                A--;
            }
        }
        if (n < 0)
            return (double)1 / (double)ans;
        else
            return ans;
    }
    double myPow(double x, int n)
    {
        return optimal(x, n); // optimal solution

        double ans = 1.0; // not working with some high test case.
        long long nn = (long long)n;
        if (nn < 0)
            nn = -nn; // Avoids overflow
        for (long i = 0; i < (nn); i++)
        {
            ans = ans * x;
        }
        cout << ans;
        if (n < 0)
            return (double)1 / (double)ans;
        else
            return ans;
    }
};