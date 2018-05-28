#include "utils.hh"

static int maxSubArray(vector<int>& nums) {
  if (nums.empty()) {
    return 0;
  }
  int res = 0, prev = 0;
  for (size_t i = 0; i < nums.size(); ++i) {
    int n = nums[i];
    int p = max(prev + n, n);
    res = max(res, p);
    prev = p;
  }
  return res;
}

int main(int argc, char** argv) {
  int a[] = {-2,1,-3,4,-1,2,1,-5,4,-1,-2,7};
  vector<int> v(a, a + arrlen(a));
  cout << maxSubArray(v) << endl;
  return 0;
}