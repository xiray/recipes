#include "../include/utils.hh"

static void reverseString(string& s) {
  if (!s.empty()) {
    size_t i = 0, j = s.size() - 1;
    while (i < j) {
      swap(s[i++], s[j--]);
    }
  }
}

int main(int argc, char** argv) {
  string s = "hello world";
  reverseString(s);
  cout << s << endl;
  return 0;
}