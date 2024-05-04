#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {

    unordered_map<string, vector<string>> map;

    for (const auto &str : strs) {

      string curr = str;
      sort(curr.begin(), curr.end());

      map[curr].push_back(str);
    }

    vector<vector<string>> groups;

    for (const auto &group : map)
      groups.push_back(group.second);

    return groups;
  }
};
