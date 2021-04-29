#include "bits/stdc++.h"
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define int long long int
#define fora(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define pb push_back
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type > ostream & operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define ANSH_DEBUG 1
#if ANSH_DEBUG == 1
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
// oset.find_by_order(k) -> Returns an iterator to the kth largest element present in the set.
// oset.order_of_key(ele) -> Return the number of integers strictly less than 'ele' in the set.

// https://cses.fi/problemset/task/1755/

void test_case() {
    string s;
    cin >> s;
    vector<int> freq(26, 0);
    for (char ch : s) {
        freq[ch - 'A']++;
    }
    bool np = 0;
    char odd;
    int oddfreq = 0;
    string a, b;
    for (int i = 0; i < 26; ++i) {
        if ((freq[i] & 1)) {
            if (np) {
                cout << "NO SOLUTION";
                return;
            }
            else {
                np = 1;
                odd = (char)'A' + i;
                oddfreq = freq[i];
            }

        }
        else {
            for (int j = 0; j < freq[i] / 2; ++j) {
                a += (char) 'A' + i;
                b += (char) 'A' + i;
            }
        }
    }
    fora(i, (oddfreq - 1) / 2) {
        a += odd;
        b += odd;
    }
    if (oddfreq)
        a += odd;
    reverse(all(b));
    a += b;
    cout << a;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin >> tc;
    while (tc--) {

        test_case();
    }






}
