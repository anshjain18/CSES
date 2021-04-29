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


// https://cses.fi/problemset/task/1622/
// https://www.youtube.com/watch?v=nYFd7VHKyWQ
void permute(vector<int>& freq, vector<char>& curr, vector<vector<char>>& allPerm, int depth = 0) {
    if (accumulate(all(freq), 0LL) == 0) {
        allPerm.pb(curr);
        return;
    }
    for (int i = 0; i < 26; ++i) {
        if (freq[i]) {   // Find the first available character at the given depth
            curr[depth] = (char) 'a' + i;
            freq[i]--;
            permute(freq, curr, allPerm, depth + 1);
            freq[i]++;
        }
    }
}
void test_case() {
    string s;
    cin >> s;
    vector<int> freq(26, 0);
    for (char ch : s) {
        freq[ch - 'a']++;
    }
    // dbg(freq);
    vector<vector<char>> allPerm;
    vector<char> curr(s.length());
    permute(freq, curr, allPerm);
    cout << allPerm.size() << "\n";
    for (vector<char> cur : allPerm) {
        for (char c : cur) cout << c;
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
