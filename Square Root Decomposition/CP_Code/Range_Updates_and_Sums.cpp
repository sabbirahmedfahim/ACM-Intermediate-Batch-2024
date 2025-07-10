// https://cses.fi/problemset/task/1735
// unsolved, instructor said i have to use segment tree
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

    int blockSize = sqrtl(n) + 1;
    vector<int> block(blockSize, 0);

    while (q--)
    {
        int type; cin >> type;

        if(type == 1)
        {
            int l, r, x; cin >> l >> r >> x;
            l--, r--;

            while (l <= r)
            {
                if(l % blockSize == 0 && l + blockSize - 1)
                {
                    block[l / blockSize] += x;
                    l += blockSize;
                }
                else 
                {
                    a[l++] = x;
                }
            }
        }
        else if(type == 2)
        {
            int l, r, x; cin >> l >> r >> x;
            ll sum = blockSize * x;

            while (l <= r)
            {
                if(l % blockSize == 0 && l + blockSize - 1)
                {
                    block[l / blockSize] = sum;
                    l += blockSize;
                }
                else 
                {
                    a[l++] = x;
                }
            }
        }
        else 
        {
            int l, r; cin>>l>>r; 
            l--, r--;
            ll sum = 0;
            while (l <= r)
            {
                if(l % blockSize == 0 && l + blockSize - 1)
                {
                    sum += block[l / blockSize];
                    l += blockSize;
                }
                else 
                {
                    sum += a[l++];
                }
            }

            cout << sum << nl;
        }
    }
    

    return 0;
}