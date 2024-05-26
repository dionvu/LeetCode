#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {

    unordered_set<int> set(nums.begin(), nums.end());

    int longest_seq = 0;

    // For some reason, iterating over the set makes the runtime so much
    // faster idk.
    for (const int &num : set) {

      if (set.find(num - 1) == set.end()) {
        int curr = num;
        int seq = 1;

        for (; set.find(curr + 1) != set.end(); curr++)
          seq++;

        if (seq > longest_seq)
          longest_seq = seq;
      }
    }

    return longest_seq;
  }
};
