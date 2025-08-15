// https://codeforces.com/contest/475/problem/D
#include <bits/stdc++.h>
#define nl '\n'
#define int long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;

struct SparseTable {
    static const int N = 2E5 + 5;
    int lg[N];
    int table[N][25];
    vector<int> a;

    void lgg(int n) {
        for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
    }
    void build(int n) {
        for (int i = 0; i < n; i++) table[i][0] = a[i];

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i <= n - (1 << j); i++) {
                table[i][j] = __gcd(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int query(int L, int R) {
        int j = lg[R - L + 1];
        return __gcd(table[L][j], table[R - (1 << j) + 1][j]);
    }
};
SparseTable st;
void solve()
{
    int n; cin >> n;
    st.a.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> st.a[i];
    }

    st.lgg(n);
    st.build(n);

    map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        int data = st.a[i];
        for (int j = i; j < n; ) // max : ologn
        {
            int lo = j, hi = n - 1, curr = j;
    
            while (lo <= hi)
            {
                int mid = lo + (hi - lo)/2;
                if(st.query(i, mid) == data)
                {
                    curr = mid;
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }
            freq[data] += curr - j + 1;
            // cerr << data << " " << curr - j + 1 << nl;

            if(curr == n - 1) break;
            data = st.query(i, curr + 1);
            j = curr + 1;
        }
    }
    
    int q; cin >> q;
    while (q--) 
    {
        int value; cin >> value;

        cout << freq[value] << nl;
    }
}
int_fast32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    solve();
    
    return 0;
}