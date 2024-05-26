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

  int search(vector<int> &nums, int target) {

    int low = 0;
    int high = nums.size();

    while (low < high) {

      const int mid = low + (high - low) / 2;

      if (target == nums[mid])
        return mid;
      else if (target > nums[mid])
        low = mid + 1;
      else
        high = mid;
    }

    return -1;
  }
};
