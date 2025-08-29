// https://cses.fi/problemset/task/1637/
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;

const int N = 1E6 + 6;
vector<int> DP_Iterative(N + 1, 1E8);
int getIterativeAns(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if(i == 0) DP_Iterative[i] = 0;
        else if(i < 10) DP_Iterative[i] = 1;
        else 
        {
            int value = i;
    
            while (value)
            {
                int dig = value % 10;
                if(dig != 0) DP_Iterative[i] = min(DP_Iterative[i], DP_Iterative[i - dig]);
    
                value /= 10;
            }
            DP_Iterative[i]++;
        }
    }
    
    return DP_Iterative[n];
}

vector<int> DP_Recursion(N + 1, 1E8);
int getRecursiveAns(int n)
{
    if(n == 0) return 0;

    if(DP_Recursion[n] != 1E8) return DP_Recursion[n];

    int tmp = n, mn = 1E8;
    while (tmp)
    {
        int dig = tmp % 10;

        if(dig != 0) mn = min(mn, getRecursiveAns(n - dig));

        tmp /= 10;
    }

    return DP_Recursion[n] = mn + 1;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;

    // cout << getIterativeAns(n) << nl; // OK
    cout << getRecursiveAns(n) << nl;

    return 0;
}