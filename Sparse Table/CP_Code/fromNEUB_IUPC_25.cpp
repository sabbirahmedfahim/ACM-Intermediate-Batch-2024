#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
const int N = 1E5 + 5;
vector<int> freq(N, 1);
map<int, int> mp;

vector<int> adjList[N];
void precCalc()
{
    for (int i = 1; i * i < N; i++)
    {
        int sq = i * i;
        for (int j = sq; j < N; j += sq)
        {
            freq[j]++;
        }
    }
    for (int i = 1; i < N; i++)
    {
        adjList[freq[i]].push_back(i);
    }
}

struct SparseTable {
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
                table[i][j] = max(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int query(int L, int R) {
        int j = lg[R - L + 1];
        return max(table[L][j], table[R - (1 << j) + 1][j]);
    }
};
SparseTable st;
void solve()
{
    st.a.resize(N);
    for (int i = 0; i < N; i++) st.a[i] = freq[i];
    st.lgg(N);
    st.build(N);

    int q; cin >> q;
    while (q--) 
    {
        int l, r; cin >> l >> r;
        int val = st.query(l, r);

        int lo = 0, hi = adjList[val].size() - 1, res = -1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo)/2;
            if (adjList[val][mid] < l) {
                res = adjList[val][mid];
                lo = mid + 1;
            }
            else 
            {
                res = adjList[val][mid];
                hi = mid - 1;
            }
        }
        
        cout << res << " ";
    }
    cout << nl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    precCalc();
    solve();
    return 0;
}