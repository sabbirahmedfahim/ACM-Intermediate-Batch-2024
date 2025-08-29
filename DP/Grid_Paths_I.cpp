// https://cses.fi/problemset/task/1638
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;

const ll N = 1E3 + 5, MOD = 1E9 + 7;
char mat[N][N];
ll dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mat[i][j];
        }
    }

    if(mat[n][n] == '*')
    {
        cout << 0 << nl; return 0;
    }

    dp[n][n] = 1;
    for (int i = n; i >= 1; i--)
    {
        for (int j = n; j >= 1; j--)
        {
            if(mat[i][j] == '*') continue;
            if(i == n && j == n) continue;

            dp[i][j] = dp[i][j + 1] + dp[i + 1][j];
            dp[i][j] %= MOD;
        }
    }

    cout << dp[1][1] << nl;

    return 0;
}