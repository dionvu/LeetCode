#include <vector>

using namespace std;

class MinStack {
public:
  vector<int> *stack;
  vector<int> *mins;

  MinStack() : stack(new vector<int>), mins(new vector<int>) {}

  void push(int val) {
    stack->push_back(val);

    if (mins->empty())
      mins->push_back(val);
    else if (val <= mins->back())
      mins->push_back(val);
  }

  void pop() {
    if (!mins->empty() && mins->back() == stack->back())
      mins->pop_back();

    if (!stack->empty())
      stack->pop_back();
  }

  int top() {
    if (!stack->empty())
      return stack->back();
    return -1;
  }

  int getMin() {
    if (!mins->empty())
      return mins->back();
    return -1;
  }
};
