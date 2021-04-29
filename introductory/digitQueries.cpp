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
int power(int base, int exp) {
    if(exp == 0) return 1;
    return base * power(base, exp - 1);
}
void test_case() {
    int q; cin >> q;
    while(q--) {
        int k; cin >> k;
        k--;
        int len = 1;
        int tot = 0;
        while(1) {
            string x, y;
            x += '1';
            fora(i, len - 1) x += '0';
            fora(i, len) y += '9';
            int a = stoll(x), b = stoll(y);
            int cur = (b - a + 1) * len;
            if(tot + cur > k) {
                break;
            }
            tot += cur;
            len++;
        }
        k -= tot;
        int start = power(10, len - 1);
        int jump = k / len;
        int idx = k % len;
        start += jump;
        string num = to_string(start);
        cout << num[idx] << "\n";
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
