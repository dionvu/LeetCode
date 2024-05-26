/**
 * @date 2024 Apr 04
 *
 * Approach:
 * We keep track of the minimum values using another vector. We know we need to
 * keep track of a value if it is less than the top of min_vals. Any value that
 * preceds a minimum value can never be popped before a this min value.
 * So we add values to min_vals that keep getting progressively less than our
 * first element.
 *
 * Time:
 * O(1) for every function as per requirements.
 */

#include <vector>

using namespace std;

class MinStack {
public:
  vector<int> *stack;
  vector<int> *min_vals;

  MinStack() : stack(new vector<int>), min_vals(new vector<int>) {}

  void push(int val) {

    stack->push_back(val);

    if (min_vals->empty() || val <= min_vals->back()) {
      min_vals->push_back(val);
    }
  }

  void pop() {
    if (stack->empty())
      return;

    // Our smallest value is about to be popped, we update our smallest value by
    // popping min_vals.
    if (stack->back() == min_vals->back())
      min_vals->pop_back();

    stack->pop_back();
  }

  int top() { return stack->back(); }

  int getMin() { return min_vals->back(); }

  ~MinStack() {
    delete stack;
    delete min_vals;
  }
};
