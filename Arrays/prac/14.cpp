/**
 * Time: O(NlogN + N)
 * O(NlogN)
 */

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {

    sort(strs.begin(), strs.end());

    string prefix = "";

    for (int i = 0; i < strs[0].length(); i++) {

      if (strs.front()[i] == strs.back()[i])
        prefix += strs.front()[i];
      else
        break;
    }

    return prefix;
  }
};
