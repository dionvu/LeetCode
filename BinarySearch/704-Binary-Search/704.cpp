/**
 * @date 2024 Apr 20
 *
 * Implementation of binary search.
 *
 * My difficulty: 3
 */

#include <vector>

using namespace std;

class Solution {
public:
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
