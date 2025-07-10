// https://codeforces.com/contest/221/problem/D
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
#define int ll
using namespace std;
const int N = 1E5 + 7;
int a[N];
int res[N];
int blockSize; // global
unordered_map<int, int> freq;
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
int_fast32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, queries; cin >> n >> queries; 
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    blockSize = sqrtl(n) + 1;

    for (int i = 0; i < queries; i++) // storing queries instead of directly doin operations, they call it OFFLINE QUERIES
    {
        int l, r; cin >> l >> r;
        q[i].l = l;
        q[i].r = r;
        q[i].idx = i;
    }
    
    sort(q, q + queries, cmp);

    int curr_l = 0, curr_r = -1, l, r;
    // ll curr_ans = 0;
    int distinct_cnt = 0;
    for (int i = 0; i < queries; i++)
    {
        l = q[i].l, r = q[i].r;
        l--, r--; // zero based index

        while (curr_r < r)
        {
            curr_r++;

            // curr_ans += a[curr_r];
            freq[a[curr_r]]++;
            if(freq[a[curr_r]] == a[curr_r]) distinct_cnt++;
            else if(freq[a[curr_r]] == a[curr_r] + 1) distinct_cnt--;
        }
        while (curr_l > l)
        {
            curr_l--;
            
            // curr_ans += a[curr_l];
            freq[a[curr_l]]++;
            if(freq[a[curr_l]] == a[curr_l]) distinct_cnt++;
            else if(freq[a[curr_l]] == a[curr_l] + 1) distinct_cnt--;
        }
        while (curr_l < l)
        {
            // curr_ans -= a[curr_l];
            freq[a[curr_l]]--;
            if(freq[a[curr_l]] == a[curr_l]) distinct_cnt++;
            else if(freq[a[curr_l]] == a[curr_l] - 1) distinct_cnt--;

            curr_l++;
        }
        while (curr_r > r)
        {
            // curr_ans -= a[curr_r];
            freq[a[curr_r]]--;
            if(freq[a[curr_r]] == a[curr_r]) distinct_cnt++;
            else if(freq[a[curr_r]] == a[curr_r] - 1) distinct_cnt--;

            curr_r--;
        }

        res[q[i].idx] = distinct_cnt;
        
        // res[q[i].idx] = curr_ans;
    }
    
    for (int i = 0; i < queries; i++)
    {
        // cout << q[i].l << " " << q[i].r << nl;
        cout << res[i] << nl;
    }

    return 0;
}