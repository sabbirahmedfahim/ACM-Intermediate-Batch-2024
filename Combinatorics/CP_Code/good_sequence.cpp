// https://judge.eluminatis-of-lu.com/p/1213
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;

template <typename T> using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; // less_equal for multiset

const int MOD = 1E9 + 7;
ll Pow(ll a, ll b) // O(log b)
{
    ll ans = 1 % MOD;
    a %= MOD;
    if (a < 0) a += MOD;
    while (b) 
    {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for(auto &e : a) cin >> e;

    pbds<int> L, R;
    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        R.insert(a[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        R.erase(R.find_by_order(R.order_of_key(a[i]))); // in this way we can erase elements from a multiset

        ll l = L.order_of_key(a[i]), r = R.order_of_key(a[i]);

        ans += ((Pow(2, l) - 1) * (Pow(2, r) - 1)) % MOD;
        ans %= MOD;

        L.insert(a[i]);
    }
    
    cout << ans << nl;
}
int main() 
{ 
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}