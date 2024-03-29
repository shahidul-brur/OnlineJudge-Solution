/* @nazarbek.altybay */

#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define pt pair<int, int>

#define pb push_back
#define mp make_pair

#define f first
#define s second

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = (int) 1e9 + 7;
const int MAXN = (int) 1e6 + 7;

const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};

int n, h, w;
char s[MAXN];

ll u[MAXN];
ll d[MAXN];
ll l[MAXN];
ll r[MAXN];

ll a[MAXN];
ll b[MAXN];

ll pos_x = 0, pos_y = 0;

inline ll getU(ll pos) {
  if (pos <= n) return u[pos];
  ll k = (pos - 1) / n;
  ll npos = pos % n;
  if (npos == 0) npos = n;
  return min(u[n] + min(0ll, pos_x) * (k - 1), k * pos_x + u[npos]);
}

inline ll getD(ll pos) {
  if (pos <= n) return d[pos];
  ll k = (pos - 1) / n;
  ll npos = pos % n;
  if (npos == 0) npos = n;
  return max(d[n] + max(0ll, pos_x) * (k - 1), k * pos_x + d[npos]);
}

inline ll getL(ll pos) {
  if (pos <= n) return l[pos];
  ll k = (pos - 1) / n;
  ll npos = pos % n;
  if (npos == 0) npos = n;
  return min(l[n] + min(0ll, pos_y) * (k - 1), k * pos_y + l[npos]);
}

inline ll getR(ll pos) {
  if (pos <= n) return r[pos];
  ll k = (pos - 1) / n;
  ll npos = pos % n;
  if (npos == 0) npos = n;
  return max(r[n] + max(0ll, pos_y) * (k - 1), k * pos_y + r[npos]);
}

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif

  scanf("%d%d%d", &n, &h, &w);
  scanf("\n%s", s + 1);

  for (int i = 1; i <= n; i++) {
    if (s[i] == 'U') pos_x--;
    if (s[i] == 'D') pos_x++;
    if (s[i] == 'L') pos_y--;
    if (s[i] == 'R') pos_y++;
    u[i] = min(u[i - 1], pos_x);
    d[i] = max(d[i - 1], pos_x);
    l[i] = min(l[i - 1], pos_y);
    r[i] = max(r[i - 1], pos_y);
  }
  bool f1 = 0;
  bool f2 = 0;
  vector<ll> as;
  vector<ll> bs;
  for (int x = 1; x <= h; x++) {
    a[x] = (ll) 1e13;
    ll low = 1;
    ll high = (ll) 1e13;
    while (low <= high) {
      ll mid = (low + high) / 2;
      if (x + getU(mid) <= 0 || x + getD(mid) > h) {
        a[x] = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    as.pb(a[x]);
    if (a[x] == (ll) 1e13) {
      f1 = 1;
    }
  }
  for (int y = 1; y <= w; y++) {
    b[y] = (ll) 1e13;
    ll low = 1;
    ll high = (ll) 1e13;
    while (low <= high) {
      ll mid = (low + high) / 2;
      if (y + getL(mid) <= 0 || y + getR(mid) > w) {
        b[y] = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    bs.pb(b[y]);
    if (b[y] == (ll) 1e13) {
      f2 = 1;
    }
  }
  if (f1 && f2) {
    puts("-1");
    return 0;
  }
  sort(as.begin(), as.end());
  sort(bs.begin(), bs.end());
  int ans = 0;
  int cnt = 0;
  for (int x = 1; x <= h; x++) {
    // a[x] == b[y]
    cnt = upper_bound(bs.begin(), bs.end(), a[x]) - lower_bound(bs.begin(), bs.end(), a[x]);
    ans = (ans + 1ll * cnt * a[x]) % INF;
    // a[x] < b[y]
    cnt = bs.end() - upper_bound(bs.begin(), bs.end(), a[x]);
    ans = (ans + 1ll * cnt * a[x]) % INF;
  }
  for (int y = 1; y <= w; y++) {
    // b[y] < a[x];
    cnt = as.end() - upper_bound(as.begin(), as.end(), b[y]);
    ans = (ans + 1ll * cnt * b[y]) % INF;
  }
  cout << ans;
  return 0;
}