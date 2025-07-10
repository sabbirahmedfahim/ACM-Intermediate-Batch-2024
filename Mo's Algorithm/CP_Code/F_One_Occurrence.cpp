// https://codeforces.com/contest/1000/problem/F 
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
const int N = 5E5 + 7;
int a[N];
int res[N];
int blockSize; // global
int block[N] = {0};
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

    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    blockSize = sqrtl(n) + 1;
    int queries; cin >> queries;

    for (int i = 0; i < n; i++) // storing queries instead of directly doin operations, they call it OFFLINE QUERIES
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
    auto getAns = [&]()
    {
        if(distinct_cnt == 0) return 0;
        for (int i = 0; i < blockSize; i++)
        {
            if(block[i] != 0)
            {
                int suru = i * blockSize;
                int shes = min(n, suru + blockSize);
                for (int j = suru; j < shes; j++)
                {
                    if(freq[j] == 1) return j;
                }
            }
        }
    };
    for (int i = 0; i < queries; i++)
    {
        l = q[i].l, r = q[i].r;
        l--, r--; // zero based index

        while (curr_r < r)
        {
            curr_r++;

            // curr_ans += a[curr_r];
            freq[a[curr_r]]++;
            if(freq[a[curr_r]] == 1) block[a[curr_r] / blockSize]++, distinct_cnt++;
            else if(freq[a[curr_r]] == 2) block[a[curr_r] / blockSize]--, distinct_cnt--;
        }
        while (curr_l > l)
        {
            curr_l--;
            
            // curr_ans += a[curr_l];
            freq[a[curr_l]]++;
            if(freq[a[curr_l]] == 1) block[a[curr_l] / blockSize]++, distinct_cnt++;
            else if(freq[a[curr_l]] == 2) block[a[curr_l] / blockSize]--, distinct_cnt--;
        }
        while (curr_l < l)
        {
            // curr_ans -= a[curr_l];
            freq[a[curr_l]]--;
            if(freq[a[curr_l]] == 1) block[a[curr_l] / blockSize]++, distinct_cnt++;
            else if(freq[a[curr_l]] == 0) block[a[curr_l] / blockSize]--, distinct_cnt--;

            curr_l++;
        }
        while (curr_r > r)
        {
            // curr_ans -= a[curr_r];
            freq[a[curr_r]]--;
            if(freq[a[curr_r]] == 1) block[a[curr_r] / blockSize]++, distinct_cnt++;
            else if(freq[a[curr_r]] == 0) block[a[curr_r] / blockSize]--, distinct_cnt--;

            curr_r--;
        }

        res[q[i].idx] = getAns();
        
        // res[q[i].idx] = curr_ans;
    }
    
    for (int i = 0; i < queries; i++)
    {
        cout << res[i] << nl;
    }

    return 0;
}