// Efficiently perform range sum queries and point updates on an array using square root decomposition.
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n,  q; cin >> n >> q;
    ll blockSize = sqrtl(n) + 1; // 1 for extra block

    vector<int> a(n);
    for(auto &e : a) cin >> e;

    vector<int> block(blockSize, 0);
    for (int i = 0; i < q; i++)
    {
        block[i / blockSize] += a[i];
    }
    
    while (q--)
    {
        int type; cin >> type;
        if(type == 1) // l to r sum
        {
            int l, r; cin >> l >> r;
            int sum = 0;
            while (l <= r)
            {
                // full block can be taken
                if(l % blockSize == 0 && l + blockSize - 1 <= r)
                {
                    sum += block[l / blockSize];

                    l += blockSize; // next block
                }
                else 
                {
                    sum += a[l++];
                }
            }
        }
        else // set a[i] = x
        {
            int i, x; cin >> i >> x;

            block[i / blockSize] -= a[i];
            a[i] = x;
            block[i / blockSize] += a[i];
        }
    }
    

    return 0;
}