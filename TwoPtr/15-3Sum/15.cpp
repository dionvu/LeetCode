#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {

    vector<vector<int>> triplets;

    sort(nums.begin(), nums.end());

    int start;
    int end;

    for (int i = 0; i < nums.size(); i++) {

      // Makes sure that our fixed element hasn't already been checked for
      // triplets.
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      start = i + 1;
      end = nums.size() - 1;

      while (start < end) {

        const int target = -nums[i];
        const int sum = nums[start] + nums[end];

        if (target == sum) {

          triplets.push_back({nums[i], nums[start], nums[end]});

          // Continue searching for triplet with curr fixed.

          // Ignore duplicates
          while (start < end && nums[start + 1] == nums[start])
            start++;

          // Ignore duplicates
          while (end > start && nums[end] == nums[end - 1])
            end--;

          // Moves to next unique
          start++;
          end--;
        } else if (sum > target)
          // We only need to check like this because the array is sorted so if
          // sum is too big, we must move end.
          end--;
        else
          start++;
      }
    }

    return triplets;
  }
};
