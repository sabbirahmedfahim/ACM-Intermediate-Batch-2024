#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
int cs = 1;
void solve()
{
    cout << "Case " << cs++ << ":" << nl;
    
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(auto &e : a) cin >> e;

    int blockSz = sqrtl(n) + 1;
    vector<int> block(blockSz);
    for (int i = 0; i < n; i++)
    {
        block[i / blockSz] += a[i];
    }

    while (q--)
    {
        int type; cin >> type;

        if(type == 1)
        {
            int x; cin >> x; 
            cout << a[x] << nl;

            block[x / blockSz] -= a[x];
            a[x] = 0;
        }
        else if(type == 2)
        {
            int x, u; cin >> x >> u;
            block[x / blockSz] += u;
            a[x] += u;
        }
        else
        {
            int l, r; cin >> l >> r;

            ll sum = 0;
            while (l <= r)
            {
                if(l % blockSz == 0 && l + blockSz - 1 <= r)
                {
                    sum += block[l / blockSz];
                    l += blockSz;
                }
                else 
                {
                    sum += a[l];
                    l++;
                }
            }
            
            cout << sum << nl;
        }
    }
    
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    for(int tt = 1; tt <= t; tt++)
    {
        // cout << "TEST CASE-" << tt << nl;
        solve();
    }

    return 0;
}
// https://lightoj.com/problem/curious-robin-hood