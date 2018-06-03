#include "../include/utils.hh"

static vector<pair<int, int> > matchPairs(const vector<int>& a, const vector<int>& b) {
  vector<pair<int, int> > res;
  size_t m = a.size(), n = b.size();
  size_t i = 0, j = 0;
  while (i < m || j < n) {
    if (i < m && j < n) {
      if (a[i] == b[j]) {
        res.push_back(make_pair(a[i++], b[j++]));
      }
      else if (a[i] < b[j]) {
        res.push_back(make_pair(a[i++], 0));
      }
      else {
        res.push_back(make_pair(0, b[j++]));
      }
    }
    else if (i < m) {
      res.push_back(make_pair(a[i++], 0));
    }
    else {
      assert(j < n);
      res.push_back(make_pair(0, b[j++]));
    }
  }
  return res;
}

int main(int argc, char** argv) {
  vector<int> a = {1,2,4,5,7};
  vector<int> b = {1,3,4,6,7};
  vector<pair<int, int> > prs = matchPairs(a, b);
  for (size_t i = 0; i < prs.size(); i++) {
    if (i != 0) {
      cout << ",";
    }
    cout << "(" << prs[i].first << "," << prs[i].second << ")";
  }
  cout << endl;
  return 0;
}