#include "../include/utils.hh"

static void _qsort(vector<int>& a, size_t begin, size_t end) {
  if (begin >= end) {
    return;
  }
  const int pivot = a[begin];
  size_t i = begin, j = end;
  while (1) {
    while (i < end && a[i] < pivot) {
      i++;
    }
    while (j > begin && a[j] >= pivot) {
      j--;
    }
    if (i >= j) {
      break;
    }
    swap(a[i], a[j]);
  }
  _qsort(a, begin, j);
  _qsort(a, j + 1, end);
}

static void qsort(vector<int>& a) {
  size_t n = a.size();
  if (n > 1) {
    _qsort(a, 0, n - 1);
  }
}

int main(int argc, char** argv) {
  srand(1);
  vector<int> a;
  for (int i = 0; i < 10; ++i) {
    a.push_back(random() % 100);
  }
  cout << "---\n" << a << endl;
  qsort(a);
  cout << "sorted ->\n" << a << endl;
  return 0;
}
