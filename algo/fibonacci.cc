#include <iostream>
#include <map>

using namespace std;

static int fib(int n) {
  if (n < 2) {
    return n;
  }
  return fib(n - 1) + fib(n - 2);
}

static int fib_non_recursive(int n) {
  if (n < 2) {
    return n;
  }
  int k0 = 0, k1 = 1;
  for (int i = 2; i < n; ++i) {
    int k = k0 + k1;
    k0 = k1;
    k1 = k;
  }
  return k0 + k1;
}

static int fib_with_cache(int n) {
  if (n < 2) {
    return n;
  }
  static map<int, int> cache;
  map<int, int>::const_iterator it = cache.find(n);
  if (it != cache.end()) {
    return it->second;
  }
  int res = fib_with_cache(n - 1) + fib_with_cache(n - 2);
  return cache.insert(make_pair(n, res)).first->second;
}

int main(int argc, char** argv) {
  const int N = 40;
  for (int i = 0; i <= N; ++i) {
    cout << "fib(" << i << "): " << fib(i) << endl;
  }
  for (int i = 0; i <= N; ++i) {
    cout << "fib(" << i << "): " << fib_non_recursive(i) << endl;
  }
  for (int i = 0; i <= N; ++i) {
    cout << "fib(" << i << "): " << fib_with_cache(i) << endl;
  }
  return 0;
}
