#include <iostream>
using namespace std;

int main() {
  int n, na, nb;
  cin >> n >> na >> nb;
  int loop_a[300], loop_b[300];
  int mat[][5] = {{0, 0, 1, 1, 0},
                  {1, 0, 0, 1, 0},
                  {0, 1, 0, 0, 1},
                  {0, 0, 1, 0, 1},
                  {1, 1, 0, 0, 0}};
  for (int i = 0; i < na; i++) cin >> loop_a[i];
  for (int i = 0; i < nb; i++) cin >> loop_b[i];
  int score_a = 0, score_b = 0;
  for (int i = 0; i < n; i++) {
    score_a += mat[loop_a[i % na]][loop_b[i % nb]];
    score_b += mat[loop_b[i % nb]][loop_a[i % na]];
  }
  cout << score_a << ' ' << score_b << endl;
}