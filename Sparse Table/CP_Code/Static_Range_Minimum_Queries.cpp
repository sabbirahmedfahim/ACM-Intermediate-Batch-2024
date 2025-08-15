// https://cses.fi/problemset/task/1647
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
const int N = 2E5 + 5;
int lg[N];
int table[N][25]; // extend upto 30

vector<int> a;
void lgg(int n)
{
    for(int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
}
void SparseTable(int n)
{
    for(int i = 0; i < n; i++) table[i][0] = a[i];

    for(int j = 1; (1 << j) <= n; j++)
    {
        for(int i = 0; i <= n - (1 << j); i++)
        {
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int query(int L, int R)
{
    int j = lg[R - L + 1];
    return min(table[L][j], table[R - (1 << j) + 1][j]);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q; cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        int data; cin >> data;
        a.push_back(data);
    }
    
    lgg(n);
    SparseTable(n);

    while (q--)
    {
        int l, r; cin >> l >> r;
        l--, r--;

        cout << query(l, r) << nl;
    }
    

    return 0;
}