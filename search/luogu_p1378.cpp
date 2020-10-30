#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int n;
double xa, xb, ya, yb;
double x[10], y[10], r[10];
double mxocp;
bool used[10];
const double PI = 3.1415926535;

double get_r(int i) {
  double dx = min(abs(x[i] - xa), abs(xb - x[i]));
  double dy = min(abs(y[i] - ya), abs(yb - y[i]));
  double ans_r = min(dx, dy);
  for (int j = 1; j <= n; j++)
    if (i != j && used[j]) {
      double d =
          sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
      ans_r = min(ans_r, max(d - r[j], 0.0));
    }
  return ans_r;
}

void dfs(int i, double ocp) {
  if (i > n) {
    mxocp = max(mxocp, ocp);
    return;
  }
  for (int j = 1; j <= n; j++)
    if (!used[j]) {
      r[j] = get_r(j);
      used[j] = 1;
      dfs(i + 1, ocp + r[j] * r[j] * PI);
      used[j] = 0;
    }
}

int main() {
  cin >> n >> xa >> ya >> xb >> yb;
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
  dfs(1, 0.0);
  cout << int(abs(yb - ya) * abs(xb - xa) - mxocp + 0.5) << endl;
  return 0;
}