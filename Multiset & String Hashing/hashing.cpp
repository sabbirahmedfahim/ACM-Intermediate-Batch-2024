#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;

// collusion rate = 1 / MOD; if i use double hashing collusion rate will be 1 / (MOD1 * MOD2);
// const __int128 MOD = 202206214218227; // for __int128 datatype

const int N = 1e6 + 5;
const int Base = 129;
const int MOD = 1e9 + 7;

ll h[N], po[N];
void generatePrefixHash(string &s) // O( |s| )
{
    h[0] = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        h[i] = ((h[i - 1] * Base) + s[i]) % MOD;
    }
    po[0] = 1;  // Storing the power of the Base.
    for (int i = 1; i <= s.size(); i++) 
    {
        po[i] = (po[i - 1] * Base) % MOD;
    }
}
ll generateHash(string &s) // O( |s| )
{
    ll H = 0;
    for (auto &c : s)
    {
        H = ((H * Base) + c) % MOD;
    }
    return H;
}
ll getHash(int l, int r) // O(1)
{
    if (l == 0) return h[r];
    return (h[r] - (h[l - 1] * po[r - l + 1] % MOD) + MOD) % MOD;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string s1, s2;
    s1 = "abcabababc", s2 = "abc";
    // cin >> s1 >> s2;
    generatePrefixHash(s1);
    ll hashOfS2 = generateHash(s2);
    for (int i = 0; i + s2.size() <= s1.size(); i++) // O( |s| )
    {
        if (getHash(i, i + s2.size() - 1) == hashOfS2) // O(1)
        {
            cout << i << "\n";
        }
    }

    return 0;
}