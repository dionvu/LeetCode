#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed) {

    map<int, int> map;

    for (int i = 0; i < position.size(); i++)
      map[position[i]] = speed[i];

    vector<double> stack;
    for (auto i = map.rbegin(); i != map.rend(); i++) {
      const double p = i->first;
      const double s = i->second;

      stack.push_back((target - p) / s);

      if (stack.size() >= 2 && stack.back() <= stack[stack.size() - 2])
        stack.pop_back();
    }

    return stack.size();
  }
};
