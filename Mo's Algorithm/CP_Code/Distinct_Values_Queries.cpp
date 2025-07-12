// https://cses.fi/problemset/task/1734/
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
const int N = 2E5 + 5;
int blockSize;
int a[N];
int res[N];
int freq[N] = {0};
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
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    int n, queries; cin >> n >> queries;
    /*
    trick is: since n <= 2E5, maximum DISTINCT values will be 2E5, kokhonoi 1E9 hobe na :D
    */
    map<int, int> mp;
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(!mp.count(a[i])) mp[a[i]] = idx++; // i te a[i]
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = mp[a[i]];
        // cout << a[i] << " ";
        // cout << mp[a[i]] << " ";
    }
    // cout << nl;
    
    for (int i = 0; i < queries; i++)
    {
        int l, r; cin >> l >> r;
        q[i].l = l, q[i].r = r, q[i].idx = i;
    }
    
    blockSize = sqrtl(n) + 1;
    sort(q, q + queries, cmp);
 
    int curr_l = 0, curr_r = -1, l, r;
    int distinct_values = 0;
 
    // ll curr_ans = 0;
    for (int i = 0; i < queries; i++)
    {
        l = q[i].l, r = q[i].r;
        l--, r--;
 
        while (curr_r < r)
        {
            curr_r++;
 
            freq[a[curr_r]]++;
            if(freq[a[curr_r]] == 1) distinct_values++;
            // curr_ans += a[curr_r];
        }
        while (curr_l > l)
        {
            curr_l--;
 
            freq[a[curr_l]]++;
            if(freq[a[curr_l]] == 1) distinct_values++;
            // curr_ans += a[curr_l];
        }
        while (curr_l < l)
        {
            // curr_ans -= a[curr_l];
            freq[a[curr_l]]--;
            if(freq[a[curr_l]] == 0) distinct_values--;
 
            curr_l++;
        }
        while (curr_r > r)
        {
            // curr_ans += a[curr_r];
            freq[a[curr_r]]--;
            if(freq[a[curr_r]] == 0) distinct_values--;
 
            curr_r--;
        }

 
        res[q[i].idx] = distinct_values;
        // res[q[i].idx] = curr_ans;
    }
 
    for (int i = 0; i < queries; i++)
    {
        cout << res[i] << nl;
    }
    
    
    return 0;
}