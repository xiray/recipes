#include "../include/utils.hh"

static int uniqPath(int m, int n) {
  if (m == 1 || n == 1) {
    return 1;
  }
  return uniqPath(m - 1, n) + uniqPath(m, n - 1);
}

int main(int argc, char** argv) {
  int m = 6, n = 4;
  cout << m << "x" << n << ": " << uniqPath(m, n) << endl;
  return 0;
}