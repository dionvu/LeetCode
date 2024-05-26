#include <unordered_map>
#include <vector>

class Solution {
public:
  bool containsDuplicate(std::vector<int> &nums) {
    std::unordered_map<int, int> map;

    for (const auto &num : nums) {
      map[num]++;
      if (map[num] > 1)
        return true;
    }

    return false;
  }
};
