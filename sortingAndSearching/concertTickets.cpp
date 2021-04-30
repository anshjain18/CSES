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

void test_case() {
    int n, m;
    cin >> n >> m;
    int price[n];
    fora(i, n) cin >> price[i];
    map<int, int> mp;
    for (auto it : price) mp[it]++;
    int money[m];
    fora(i, m) cin >> money[i];
    vector<int> ans;
    for (auto it : money) {
        if (mp.empty()) {
            ans.push_back(-1);
            continue;
        }
        auto x = mp.lower_bound(it);
        if (x->first == it) {
            ans.push_back(x->first);
            mp[x->first]--;
            if (mp[x->first] == 0) {
                mp.erase(x->first);
            }
            continue;
        }
        if (x == mp.begin()) {
            ans.push_back(-1);
        }
        else {
            --x;
            ans.push_back(x->first);
            mp[x->first]--;
            if (mp[x->first] == 0) mp.erase(x->first);
        }
    }



    for (auto it : ans) cout << it << "\n";

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
