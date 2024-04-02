#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @date 2024 Apr 1
 * Approach:
 * Fill a map with the elements of the array and their index.
 * Next, for every element check if target - element is in the map.
 * If it is, that means we have a pair that adds to target.
 *
 * Time:
 * O(N + N)
 * = O(2N)
 * = O(N)
 *
 * Space:
 * O(N)
 * Our map takes up N space. Answer array is not extra space.
 */
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;

    // Fills map with elements and their index.
    // Duplicates do not matter because once we loop through the array again, we
    // don't care about any (if any) of the same elements in between.
    // e.g. [1, 0, 1, 0, 1] target = 2
    // We don't care if answer is [0, 2] or [0, 4] (or even [2, 4] but I
    // digress)
    for (int i = 0; i < nums.size(); i++) {
      map[nums[i]] = i;
    }

    // The answer array.
    vector<int> answer;

    for (int i = 0; i < nums.size(); i++) {

      // Validates answer won't contain two same indexes.
      // If target - num exists in the map then we add num's index and (target -
      // num)'s index.
      if (map[target - nums[i]] && i != map[target - nums[i]]) {
        answer.push_back(i);
        answer.push_back(map[target - nums[i]]);
        return answer;
      }
    }

    // Sentinel value of an empty array if we have none matching.
    return answer;
  }
};
