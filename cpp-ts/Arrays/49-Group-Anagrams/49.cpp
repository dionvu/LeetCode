#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> group_anagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> map;

    for (const auto &str : strs) {
      string sorted = str;
      sort(sorted.begin(), sorted.end());

      // Or map.find(key) == map.end();
      if (map.empty())
        map[sorted] = {};

      map[sorted].push_back(str);
    }

    vector<vector<string>> groups;

    for (const auto &group : map)
      groups.push_back(group.second);

    return groups;
  };
};
