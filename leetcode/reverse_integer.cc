#include "../include/utils.hh"

static int reverseInteger(int n) {
  long long res = 0;
  while (n != 0) {
    int k = n % 10;
    res = res * 10 + k;
    if (res > INT_MAX || res < INT_MIN) {
      return 0;
    }
    n /= 10;
  }
  return res;
}

int main(int argc, char** argv) {
  int n = -123456;
  cout << n << ": " << reverseInteger(n) << endl;
  return 0;
}