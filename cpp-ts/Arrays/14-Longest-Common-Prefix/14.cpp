/**
 * @date 2024 Apr 3
 *
 * The hardest part of this problem was I had no idea what prefix meant and
 * assumed it wanted me to find any matching sequence of characters anywhere in
 * the strings. Pain.
 *
 *
 * Approach:
 * Sort the strings, the strings that differ the most are going to be the first
 * and the last string. We compare the prefix between them.
 */

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    sort(strs.begin(), strs.end());

    const string first = strs.front();
    const string last = strs.back();

    string prefix = "";

    for (int i = 0; i < first.length(); i++) {
      if (first[i] == last[i])
        prefix += first[i];
      else
        break;
    }

    return prefix;
  }
};
