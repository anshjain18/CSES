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

// https://cses.fi/problemset/task/2205/
/*********
A Gray code is a list of all 2n bit strings of length n, where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).

Your task is to create a Gray code for a given length n.
*******/
void test_case() {
    int n;
    cin >> n;
    vector<vector<int>> codes((1 << n), vector<int>(n));
    for (int i = 0; i < n; ++i) {
        int col = n - 1 - i;
        for (int j = 0; j < (1 << n); j += (1 << (i + 1))) {
            int is_rev = 0;
            int grp = j / (1 << (i + 1));
            if(grp & 1) is_rev = 1;
            int k = j;
            for(;k < j + (1 << i); k++) {
                codes[k][col] = is_rev;
            }
            for(; k < j + (1 << (i + 1)); ++k) codes[k][col] = 1 - is_rev;

        }
    }
    for(vector<int> v:codes) {
        for(int ele: v) cout << ele;
        cout << "\n";
    }
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
