#include <cstdlib>
#include <climits>
#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

template<typename T>
static inline int arrlen(const T& a) {
  return sizeof(a) / sizeof(a[0]);
}

template<typename T>
static inline ostream& operator<<(ostream& os, const vector<T>& a) {
  os << "[";
  for (size_t i = 0; i < a.size(); ++i) {
    if (i != 0) {
      os << ",";
    }
    os << a[i];
  }
  return os << "]";
}

static inline int enterNumber() {
  int n = 0;
  cout << "Enter number: ";
  cin >> n;
  return n;  
}
