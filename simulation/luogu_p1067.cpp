#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int x;
  for (int i = n; i > 0; i--) {
    cin >> x;
    if (x == 0) continue;
    if (i != n) {
      if (x > 0) cout << '+';
    }
    if (x == -1)
      cout << '-';
    else if (x != 1)
      cout << x;
    cout << 'x';
    if (i > 1) cout << '^' << i;
  }
  cin >> x;
  if (x > 0) cout << '+';
  if (x != 0) cout << x;
  cout << endl;
  return 0;
}