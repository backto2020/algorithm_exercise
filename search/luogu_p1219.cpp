#include <iostream>
using namespace std;

int n, total;
int r[50];
bool c[50], a[50], b[50];

void queen(int i) {
  if (i > n) {
    total++;
    if (total <= 3) {
      for (int j = 1; j <= n; j++) cout << r[j] << ' ';
      cout << endl;
    }
    return;
  }
  for (int j = 1; j <= n; j++)
    if (!c[j] && !a[i + j] && !b[i - j + n]) {
      r[i] = j;
      c[j] = a[i + j] = b[i - j + n] = 1;
      queen(i + 1);
      c[j] = a[i + j] = b[i - j + n] = 0;
    }
}

int main() {
  cin >> n;
  queen(1);
  cout << total;
}