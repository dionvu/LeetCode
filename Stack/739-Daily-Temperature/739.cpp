/**
 * @date 2024 Apr 6
 *
 * Approach:
 * We keep a stack of the temp that still have no temp warmer than it. This
 * means our pending_temps will always be decreasing. Once we find a temp
 * warmer, we keep popping from our pending_temps and calculating the distance
 * between their indexes to get answer[indexes.top()];
 *
 * Time:
 * Since we loop through temperatures and every temperature is only added to
 * stack or removed from stack a maximum of 2 times, our time is O(2N).
 *
 * O(N)
 */

#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {

    // Keeps track of pending_temps indexes.
    stack<int> indexes;
    // Keeps track of temps without an answer yet.
    stack<int> pending_temps;
    // Temps without answer will be 0.
    vector<int> answer(temperatures.size(), 0);

    for (int i = 0; i < temperatures.size(); i++) {

      /**
       * If the temp on top of stack is less than the curr temp, then we keep
       * removing them and calc curr temp index - temp index.
       */
      while (!pending_temps.empty() && pending_temps.top() < temperatures[i]) {
        answer[indexes.top()] = i - indexes.top();
        indexes.pop();
        pending_temps.pop();
      }

      /**
       * When our stacks are empty or the top of our stack is higher than curr
       * temp, we add the curr temp to pending.
       */
      pending_temps.push(temperatures[i]);
      indexes.push(i);
    }

    return answer;
  }
};
