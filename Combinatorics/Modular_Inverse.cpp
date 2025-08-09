#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
const int MOD = 1E9 + 7; 
// const int MOD = 100; // wrong because, prime number is must, it's not divisible

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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    // code here

    ll a = 12345, b = 3;

    ll ans1 = (((a % MOD) * Pow(b, MOD-2) % MOD)) % MOD;

    cout << ans1 << nl;

    // ll ans2 = (12345/3) % MOD;
    // cout << ans1 << " " << ans2 << nl;


    return 0;
}