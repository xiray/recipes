#include "../include/utils.hh"

static int _iMatrixChainOrder(const vector<int>& dims, size_t i, size_t j) {
  assert(j >=  i);
  if (i == j) {
    return 0;
  }
  int res = INT_MAX;
  for (size_t k = i; k < j; ++k) {
    int count = _iMatrixChainOrder(dims, i, k) +
      _iMatrixChainOrder(dims, k + 1, j) + dims[i - 1] * dims[k] * dims[j];
    if (count < res) {
      res = count;
    }
  }
  return res;
}

static int matrixChainOrder(const vector<int>& dims) {
  size_t n = dims.size();
  if (n <= 2) {
    return 0;
  }
  return _iMatrixChainOrder(dims, 1, n - 1);
}

int main(int argc, char** argv) {
  cout << matrixChainOrder({10,20,30}) << endl;
  cout << matrixChainOrder({10,20,30,40,30}) << endl;
  cout << matrixChainOrder({40,20,30,10,30}) << endl;
  return 0;
}