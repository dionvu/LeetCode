/**
 * @date 2024 Apr 6
 *
 * Approach:
 * Map the elements to their frequency, add them to a vector, return the first k
 * elements of that vector.
 */

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {

    unordered_map<int, int> map;

    for (const int &n : nums)
      map[n]++;

    vector<pair<int, int>> freq(map.begin(), map.end());

    // Return true if correct order
    sort(freq.begin(), freq.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
           return a.second > b.second;
         });

    vector<int> topK;

    for (int i = 0; i < k; i++)
      topK.push_back(freq[i].first);

    return topK;
  }
};
