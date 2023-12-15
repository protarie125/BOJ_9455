#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

ll m, n;
vvl bd;

ll solve() {
  auto ret = ll{0};
  auto moved = ll{0};
  do {
    moved = 0;
    for (auto c = 0; c < n; ++c) {
      for (auto r = m - 1; 1 <= r; --r) {
        if (0 == bd[r][c] && 1 == bd[r - 1][c]) {
          ++ret;
          ++moved;
          bd[r][c] = 1;
          bd[r - 1][c] = 0;
        }
      }
    }
  } while (0 < moved);

  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  cin >> t;
  while (0 < (t--)) {
    cin >> m >> n;

    bd = vvl(m, vl(n));
    for (auto&& row : bd) {
      for (auto&& x : row) {
        cin >> x;
      }
    }

    cout << solve() << '\n';
  }

  return 0;
}