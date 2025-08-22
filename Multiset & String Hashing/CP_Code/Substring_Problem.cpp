// Always Use Double Hashing.

// https://www.spoj.com/problems/SUB_PROB/
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
 
const int N = 1e6 + 5;
const int Base = 129;
const int MOD = 1e9 + 7;
 
ll h[N], po[N];
 
void generatePrefixHash(const string &s) {
    h[0] = s[0];
    for (int i = 1; i < s.size(); i++)
        h[i] = (h[i - 1] * Base + s[i]) % MOD;
    po[0] = 1;
    for (int i = 1; i <= s.size(); i++)
        po[i] = (po[i - 1] * Base) % MOD;
}
 
ll getHash(int l, int r) {
    if (l == 0) return h[r];
    return (h[r] - (h[l - 1] * po[r - l + 1] % MOD) + MOD) % MOD;
}
 
ll generateHash(const string &s) {
    ll H = 0;
    for (auto &c : s)
        H = (H * Base + c) % MOD;
    return H;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
    string s; cin >> s;
    int q; cin >> q;
 
    vector<string> queries(q);
    set<int> lengths;
    for (int i = 0; i < q; i++) {
        cin >> queries[i];
        lengths.insert(queries[i].size());
    }
 
    generatePrefixHash(s);
 
    map<int, set<ll>> substrHashes;
    for (int len : lengths) {
        if (len > s.size()) continue;
        for (int i = 0; i + len <= s.size(); i++)
            substrHashes[len].insert(getHash(i, i + len - 1));
    }
 
    for (auto &x : queries) {
        ll hx = generateHash(x);
        if (substrHashes[x.size()].count(hx)) printf("Y\n");
        else printf("N\n");
    }
} 