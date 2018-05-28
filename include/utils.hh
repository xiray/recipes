#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

template<typename T>
inline int arrlen(const T& a) {
  return sizeof(a) / sizeof(a[0]);
}

template<typename T>
inline ostream& operator<<(ostream& os, const vector<T>& a) {
  os << "[";
  for (size_t i = 0; i < a.size(); ++i) {
    if (i != 0) {
      os << ",";
    }
    os << a[i];
  }
  return os << "]";
}
