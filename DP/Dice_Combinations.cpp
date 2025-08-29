// https://cses.fi/problemset/task/1635
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;

const int MOD = 1E9 + 7, N = 1E6 + 5;
vector<ll> dp(N, -1);
ll res(ll n)
{
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];

    return dp[n] = (res(n - 1) + res(n - 2) + res(n - 3) + res(n - 4) + res(n - 5) + res(n - 6)) % MOD;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll n; cin >> n;
    cout << res(n) << nl;

    return 0;
}