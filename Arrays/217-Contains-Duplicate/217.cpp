/**
 * @date 2024 March 22
 * Time: O(N)
 * Space: O(N)
 */

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_map<int, int> map;

    for (const int num : nums) {
      if (map.find(num) == map.end())
        map[num] = 0;

      map[num] += 1;

      if (map[num] >= 2)
        return true;
    }

    return false;
  }
};
