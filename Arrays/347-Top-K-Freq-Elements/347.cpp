#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> map;

    for (const auto &num : nums)
      map[num]++;

    vector<pair<int, int>> pairs;

    for (const auto &pair : map)
      pairs.push_back(pair);

    // Similar to JS sort but you return true if we should swap a with b.
    sort(pairs.begin(), pairs.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
           return a.second > b.second;
         });

    vector<int> topK;
    int i = 0;

    for (const auto &pair : pairs) {
      if (i >= k)
        break;

      topK.push_back(pair.first);

      i++;
    }

    return topK;
  }
};
