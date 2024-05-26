#include <vector>

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {

    const int idx = search(nums, target);
    vector<int> range;

    if (idx == -1) {
      range.push_back(-1);
      range.push_back(-1);
      return range;
    }

    int low = idx;
    while (low > 0 && nums[low - 1] == target)
      low--;

    int high = idx;
    while (high < nums.size() - 1 && nums[high + 1] == target)
      high++;

    range.push_back(low);
    range.push_back(high);

    return range;
  }

  int search(vector<int> &vec, int target) {

    int lo = 0;
    int hi = vec.size();

    while (lo < hi) {

      const int m = lo + (hi - lo) / 2;
      const int val = vec[m];

      if (target == val)
        return m;
      else if (target > val)
        lo = m + 1;
      else
        hi = m;
    }

    return -1;
  }
};
