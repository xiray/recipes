#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
  	vector<int> res;
  	map<int, int> visited;
  	for (int i = 0; i < nums.size(); ++i) {
  		int n = target - nums[i];
  		map<int, int>::const_iterator j = visited.find(n);
  		if (j != visited.end()) {
  			res.push_back(j->second);
  			res.push_back(i);
  			break;
  		}
  		visited.insert(make_pair(nums[i],  i));
  	}
  	return res;
  }
};
