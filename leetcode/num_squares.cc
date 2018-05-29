#include "../include/utils.hh"

static int numSquares(int n) {
  vector<int> res(n + 1, n);
  res[0] = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 1; i + j * j <= n; ++j) {
      res[i + j * j] = min(res[i + j * j], res[i] + 1);
    }
  }
  return res[n];
}

int main(int argc, char** argv) {
  int n = 0;
  cout << "Enter number: ";
  cin >> n;
  cout << "Number of squares: " << numSquares(n) << endl;
  return 0;
}