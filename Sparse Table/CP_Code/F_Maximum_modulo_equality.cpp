// https://codeforces.com/contest/2050/problem/F
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
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
    int n, q; cin >> n >> q;
    st.a.resize(n);

    vector<int> tmp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tmp[i];
    }

    st.a[0] = 0;
    
    for (int i = 1; i < n; i++) {
        st.a[i] = abs(tmp[i] - tmp[i - 1]);
    }

    st.lgg(n);
    st.build(n);

    while (q--) 
    {
        int l, r; cin >> l >> r;
        l--, r--;
        
        if(l == r) cout << 0 << " ";
        else cout << st.query(l + 1, r) << " ";
    }
    cout << nl;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}