/**
 * @date 2024 Apr 2
 *
 * Approach:
 * Populates a set with the values of nums. Goes through the vector nums, and
 * checks if each num can be the start of a sequence (if num - 1 doesn't exist).
 * Repeatedly add one to num and check for existance to calculate a sequence.
 *
 * Time:
 * The check for start of sequence makes our solution O(N) instead of having to
 * calculate each num as the start of a sequence.
 * O(N)
 */

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> set(nums.begin(), nums.end());

    int longest = 0;

    /**
     * Goes through our a set and checks if num - 1 exists, if it does we have
     * the start of a sequence. Else we don't need to check it because that
     * means an even longest sequence will be possible starting at num - 1.
     */
    for (const auto &num : set) {

      if (set.find(num - 1) == set.end()) {
        int curr = num;
        int streak = 1;

        /**
         * Since we visit an element a maximum of two times, one to check if its
         * a sequence, and another while iterating through the sequence, this
         * for loop + while loop is only O(N).
         *
         * In other words, each sequence is only traversed once!
         */
        while (set.find(curr + 1) != set.end()) {
          curr++;
          streak++;
        }

        if (longest < streak)
          longest = streak;
      }
    }

    return longest;
  }
};
