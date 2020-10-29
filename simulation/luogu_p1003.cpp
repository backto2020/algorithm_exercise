#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int inp[10005][4];
  for (int i = 0; i < n; i++) {
    cin >> inp[i][0] >> inp[i][1] >> inp[i][2] >> inp[i][3];
  }
  int x, y;
  bool flag = 1;
  cin >> x >> y;
  for (int i = n - 1; i >= 0; i--) {
    if (x >= inp[i][0] && x < inp[i][0] + inp[i][2] && y >= inp[i][1] &&
        y < inp[i][1] + inp[i][3]) {
      cout << i + 1 << endl;
      flag = 0;
      break;
    }
  }
  if (flag) {
    cout << -1 << endl;
  }
  return 0;
}