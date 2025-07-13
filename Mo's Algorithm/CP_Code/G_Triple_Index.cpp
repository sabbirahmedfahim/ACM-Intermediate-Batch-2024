// https://atcoder.jp/contests/abc293/tasks/abc293_g
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
const int N = 2E5 + 7;
int blockSize; // global
int freq[N] = {0};
class Q
{
    public:
    int l, r, idx;
};
Q q[N];

// bool cmp(Q q1, Q q2)
// {
//     if(q1.l / blockSize == q2.l / blockSize) return q1.r > q2.r;
//     return q1.r < q2.r;
// }
bool cmp(Q &p, Q &q) { // faster 
    if (p.l / blockSize != q.l / blockSize) return (p.l == q.l ? p.r <= q.r : p.l < q.l); // return p < q;
    return (p.l / blockSize & 1) ? (p.r < q.r) : (p.r > q.r);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, queries; cin >> n >> queries;
    vector<int> a(n);
    for(auto &e : a) cin >> e;

    blockSize = sqrtl(n) + 1;

    for (int i = 0; i < queries; i++) // storing queries instead of directly doin operations, they call it OFFLINE QUERIES
    {
        int l, r; cin >> l >> r;
        q[i].l = l;
        q[i].r = r;
        q[i].idx = i;
    }
    
    sort(q, q + queries, cmp);
    vector<ll> res(queries);

    int curr_l = 0, curr_r = -1, l, r;
    ll curr_ans = 0;
    for (int i = 0; i < queries; i++)
    {
        l = q[i].l, r = q[i].r;
        l--, r--; // zero based index

        while (curr_r < r)
        {
            curr_r++;

            curr_ans -= (1ll * freq[a[curr_r]] * (freq[a[curr_r]] - 1) * (freq[a[curr_r]] - 2))/6;
            freq[a[curr_r]]++;
            curr_ans += (1ll * freq[a[curr_r]] * (freq[a[curr_r]] - 1) * (freq[a[curr_r]] - 2))/6;
            // curr_ans += a[curr_r];
        }
        while (curr_l > l)
        {
            curr_l--;

            curr_ans -= (1ll * freq[a[curr_l]] * (freq[a[curr_l]] - 1) * (freq[a[curr_l]] - 2))/6;
            freq[a[curr_l]]++;
            curr_ans += (1ll * freq[a[curr_l]] * (freq[a[curr_l]] - 1) * (freq[a[curr_l]] - 2))/6;
            // curr_ans += a[curr_l];
        }
        while (curr_l < l)
        {
            // curr_ans -= a[curr_l];
            curr_ans -= (1ll * freq[a[curr_l]] * (freq[a[curr_l]] - 1) * (freq[a[curr_l]] - 2))/6;
            freq[a[curr_l]]--;
            curr_ans += (1ll * freq[a[curr_l]] * (freq[a[curr_l]] - 1) * (freq[a[curr_l]] - 2))/6;

            curr_l++;
        }
        while (curr_r > r)
        {
            // curr_ans -= a[curr_r];
            curr_ans -= (1ll * freq[a[curr_r]] * (freq[a[curr_r]] - 1) * (freq[a[curr_r]] - 2))/6;
            freq[a[curr_r]]--;
            curr_ans += (1ll * freq[a[curr_r]] * (freq[a[curr_r]] - 1) * (freq[a[curr_r]] - 2))/6;

            curr_r--;
        }
        
        res[q[i].idx] = curr_ans;
    }
    
    for (int i = 0; i < queries; i++)
    {
        cout << res[i] << nl;
    }

    return 0;
}