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

// https://cses.fi/problemset/task/1625/
string s;
int g[7][7];

int f(int y, int x, int i, char m) {
    if (i == 48) return 1;
    if (g[6][0]) return 0;
    if (m == 'L' && (x == 0 || g[y][x - 1]) && y > 0 && y < 6 && !g[y - 1][x] && !g[y + 1][x]) return 0;
    if (m == 'R' && (x == 6 || g[y][x + 1]) && y > 0 && y < 6 && !g[y - 1][x] && !g[y + 1][x]) return 0;
    if (m == 'U' && (y == 0 || g[y - 1][x]) && x > 0 && x < 6 && !g[y][x - 1] && !g[y][x + 1]) return 0;
    if (m == 'D' && (y == 6 || g[y + 1][x]) && x > 0 && x < 6 && !g[y][x - 1] && !g[y][x + 1]) return 0;
    if (s[i] == '?') {
        int r[] = { -1, 0, 1, 0};
        int c[] = {0, -1, 0, 1};
        int k = 0;
        for (int j = 0; j < 4; j++) {
            int yy = y + r[j];
            int xx = x + c[j];
            if (yy < 0 || yy > 6) continue;
            if (xx < 0 || xx > 6) continue;
            if (g[yy][xx]) continue;
            g[yy][xx] = true;
            k += f(yy, xx, i + 1, "ULDR"[j]);
            g[yy][xx] = false;
        }
        return k;
    }
    if (s[i] == 'L') x--;
    else if (s[i] == 'R') x++;
    else if (s[i] == 'U') y--;
    else if (s[i] == 'D') y++;
    if (x < 0 || x > 6) return 0;
    if (y < 0 || y > 6) return 0;
    if (g[y][x]) return 0;
    g[y][x] = true;
    int k = f(y, x, i + 1, s[i]);
    g[y][x] = false;
    return k;
}

void test_case() {
    cin >> s;
    g[0][0] = true;
    cout << f(0, 0, 0, 0) << endl;

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
