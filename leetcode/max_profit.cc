#include "../include/utils.hh"

static int maxProfit(const vector<int>& v) {
  size_t n = v.size();
  if (n <= 1) {
    return 0;
  }
  int res = 0, prev = 0;
  for (int i = 1; i < n; ++i) {
    int d = v[i] - v[i - 1];
    res = max(res, prev + d);
    prev = max(prev + d, 0);
  }
  return res;
}

int main(int argc, char** argv) {
  vector<int> v = {1, 2, -1, -2, 1, 3, 4, 2, 5, 3};
  cout << v << ": " << maxProfit(v) << endl;
  return 0;
}