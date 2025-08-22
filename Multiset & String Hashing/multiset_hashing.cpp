#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define int long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int_fast32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    vector<ll> hashValue(n + 1);
    for (int i = 1; i <= n; i++)
    {
        hashValue[i] = rng();
        // cout << hashValue[i] << " ";
    }
    
    vector<ll> a(n);
    for(auto &e : a) cin >> e;

    vector<ll> prefArray(n + 1), prefPermu(n + 1);
    prefArray[0] = hashValue[a[0]];
    prefPermu[0] = 0;

    for (int i = 1; i < n; i++)
    {
        prefArray[i] = prefArray[i - 1] + hashValue[a[i]];

        prefPermu[i] = prefPermu[i - 1] + hashValue[i]; 
    }
    prefPermu[n] = prefPermu[n - 1] + hashValue[n];

    // compare hash values vs hash values, forget a[]

    // task : Try XOR hasing, same same but different
    // use XOR hasing if and only if elements are distinct
    


    return 0;
}