#include <iostream>
using namespace std;

int n, m;
int nb[5];
int a[400];
int b[400];
int f[50][50][50][50];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    nb[b[i]]++;
  }
  f[0][0][0][0] = a[1];
  for (int i1 = 0; i1 <= nb[1]; i1++)
    for (int i2 = 0; i2 <= nb[2]; i2++)
      for (int i3 = 0; i3 <= nb[3]; i3++)
        for (int i4 = 0; i4 <= nb[4]; i4++) {
          int pos = 1 + i1 + 2 * i2 + 3 * i3 + 4 * i4;
          if (i1 != 0)
            f[i1][i2][i3][i4] =
                max(f[i1][i2][i3][i4], f[i1 - 1][i2][i3][i4] + a[pos]);
          if (i2 != 0)
            f[i1][i2][i3][i4] =
                max(f[i1][i2][i3][i4], f[i1][i2 - 1][i3][i4] + a[pos]);
          if (i3 != 0)
            f[i1][i2][i3][i4] =
                max(f[i1][i2][i3][i4], f[i1][i2][i3 - 1][i4] + a[pos]);
          if (i4 != 0)
            f[i1][i2][i3][i4] =
                max(f[i1][i2][i3][i4], f[i1][i2][i3][i4 - 1] + a[pos]);
        }
  cout << f[nb[1]][nb[2]][nb[3]][nb[4]] << endl;
  return 0;
}