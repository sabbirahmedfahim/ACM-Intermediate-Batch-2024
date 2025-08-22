#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
/*
1 10 100
*/
int string_to_int_right_to_left(string s)
{
    int x = 1;
    int sum = 0;
    
    for (int i = s.size() - 1; i >= 0; i--)
    {
        int val = s[i] - '0';
        // cerr << val << " ";

        val *= x;
        x *= 10;
        sum += val;
    }

    return sum;
}
int string_to_int_left_to_right(string s)
{
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int val = s[i] - '0';
        // cerr << val << " ";

        sum *= 10;
        sum += val;
    }

    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string s; cin >> s;

    cout << string_to_int_left_to_right(s) << nl;

    cout << string_to_int_right_to_left(s) << nl;

    return 0;
}