// https://cses.fi/problemset/task/1634
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;

const int MOD = 1E9 + 7, N = 1E6 + 5;
int dp[101][N];
// min no of coins to make x considering 0-i index of coins
int coin(int i, int x, vector<int> &a)
{
    if(x == 0) return 0;
    if(i == 0)
    {
        if(x % a[i] == 0) return x / a[i];
        else return 1E8;
    }

    if(dp[i][x] != -1) return dp[i][x];

    int nibo;
    if(x - a[i] >= 0) nibo = coin(i, x - a[i], a) + 1;
    else nibo = 1E8;
    int nibona = coin(i - 1, x, a);

    return dp[i][x] = min(nibo, nibona);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, x; cin >> n >> x;
    vector<int> a(n);
    for(auto &e : a) cin >> e;

    memset(dp, -1, sizeof(dp));

    int res = coin(n - 1, x, a);

    if(res == 1E8) cout << -1 << nl;
    else cout << res << nl;

    return 0;
}