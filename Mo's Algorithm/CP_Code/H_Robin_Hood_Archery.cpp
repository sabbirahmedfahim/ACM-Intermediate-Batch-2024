// https://codeforces.com/contest/2014/problem/H
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
const int N = 1E6 + 5;
int blockSize;
int res[N];
class Q
{
    public:
    int l, r, idx;
};
Q q[N];
bool cmp(Q &p, Q &q) { // faster 
    if (p.l / blockSize != q.l / blockSize) return (p.l == q.l ? p.r <= q.r : p.l < q.l); // return p < q;
    return (p.l / blockSize & 1) ? (p.r < q.r) : (p.r > q.r);
}
void solve()
{
    int n, queries; cin >> n >> queries;
    vector<int> a(n);
    for(auto &e : a) cin >> e;

    for (int i = 0; i < queries; i++)
    {
        int l,r; cin >> l >> r;
        q[i].l = l, q[i].r = r, q[i].idx = i;
    }
    
    blockSize = sqrtl(n) + 1;
    sort(q, q + queries, cmp);

    int curr_l = 0, curr_r = -1, l, r;
    ll curr_ans = 0;
    int freq[N] = {0};
    int on_off = 0;

    for (int i = 0; i < queries; i++)
    {
        int l = q[i].l - 1, r = q[i].r - 1;

        // if((r - l + 1) & 1) // i believe Mo's Algo works well when it is not intercepted
        // {
        //     res[q[i].idx] = 0; continue;
        // }

        while (curr_r < r) 
        {
            curr_r++;

            freq[a[curr_r]]++;
            if(freq[a[curr_r]] & 1) on_off++;
            else on_off--;
            // curr_ans += a[curr_r];
        }
        while (curr_l > l) 
        {
            curr_l--;

            freq[a[curr_l]]++;
            if(freq[a[curr_l]] & 1) on_off++;
            else on_off--;

            // curr_ans += a[curr_l];
        }
        while (curr_l < l) 
        {
            // curr_ans -= a[curr_l];
            freq[a[curr_l]]--;
            if(freq[a[curr_l]] & 1) on_off++;
            else on_off--;

            curr_l++;
        }
        while (curr_r > r) 
        {
            // curr_ans -= a[curr_r];
            freq[a[curr_r]]--;
            if(freq[a[curr_r]] & 1) on_off++;
            else on_off--;

            curr_r--;
        }

        if(on_off == 0) res[q[i].idx] = 1;
        else res[q[i].idx] = 0;
        
        // res[q[i].idx] = curr_ans;
    }
    for (int i = 0; i < queries; i++)
    {
        if(res[i]) cout << "YES" << nl;
        else cout << "NO" <<nl;
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