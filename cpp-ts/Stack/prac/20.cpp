#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {

    stack<char> stack;

    for (const char c : s) {
      if (c == '(' || c == '{' || c == '[')
        stack.push(c);

      else {
        if (stack.empty())
          return false;

        if ((stack.top() == '(' && c != ')') ||
            (stack.top() == '{' && c != '}') ||
            (stack.top() == '[' && c != ']'))
          return false;
        else
          stack.pop();
      }
    }

    return stack.empty();
  }
};
