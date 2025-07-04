// https://cses.fi/problemset/task/1646/
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(auto &e : a) cin >> e;

    int blockSz = sqrtl(n) + 1;
    vector<ll> block(blockSz); // each block can be more than 1E9

    for (int i = 0; i < n; i++)
    {
        block[i / blockSz] += a[i];
    }

    while (q--)
    {
        int l, r; cin >> l >> r;
        l--, r--;
        
        ll sum = 0;

        while (l <= r)
        {
            if(l % blockSz == 0 && l + blockSz - 1 <= r) 
            {
                sum += block[l / blockSz];
                l += blockSz; 
            }
            else sum += a[l++];
        }
        
        cout << sum << nl;
    }
    

    return 0;
}