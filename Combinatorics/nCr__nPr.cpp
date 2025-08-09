#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
const ll N = 2E5, MOD = 1E9 + 7;
ll fact[N + 1], factInv[N + 1];
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
void build_fact()
{
    fact[0] = fact[1] = 1;
    for (ll i = 2; i <= N; i++) fact[i] = 1ll * (fact[i - 1] * i) % MOD;
    
    factInv[N] = Pow(fact[N], MOD-2);
    for (ll i = N-1; i >= 0; i--) factInv[i] = (factInv[i + 1] * (i + 1)) % MOD;
}
ll nCr(ll n, ll r)
{
    if(n < r or n < 0 or r < 0) return 0;
    return ((fact[n] * factInv[r]) % MOD) * factInv[n - r] % MOD;
}
ll nPr(ll n, ll r) // nPr = nCr * r!
{
    if(n < r or n < 0 or r < 0) return 0;
    return (fact[n] * factInv[n - r]) % MOD;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    build_fact(); // do not forget

    return 0;
}