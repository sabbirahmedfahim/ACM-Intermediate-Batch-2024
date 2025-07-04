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
    for(auto &e : a) cin>>e;

    int blockSz = sqrtl(n) + 1;
    vector<ll> block(blockSz, 0);
    vector<ll> extra(n, 0);
    
    while (q--)
    {
        int type; cin >> type;

        if(type == 1)
        {
            int l, r, u; cin >> l >> r >> u; 
            l--, r--;
            while (l <= r)
            {
                if(l % blockSz == 0 && l + blockSz - 1 <= r)
                {
                    block[l / blockSz] += u;
                    l += blockSz;
                }
                // else block[l++] += u;
                else
                {
                    extra[l] += u;
                    l++;
                }
            }
        }
        else
        {
            int k; cin >> k; k--;
            cout << a[k] + block[k / blockSz] + extra[k] << nl;
        }
    }
    

    return 0;
}
// https://cses.fi/problemset/task/1651/