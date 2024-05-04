/**
 * @date 2024 May 04
 *
 * Approach: Using a stack, once we reach an operand, we perform the operation
 * of the top two numbers. Make sure to always perform with the second number we
 * pull off the stack as the first number. Once operation is complete, we can
 * just put it back on the stack.
 *
 * Time: O(N)
 * Space: O(N)
 */

#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {

    const unordered_set<string> ops = {"+", "-", "*", "/"};
    stack<int> stack;

    for (const auto &token : tokens) {
      if (ops.find(token) != ops.end()) {

        int num1 = stack.top();
        stack.pop();

        int num2 = stack.top();
        stack.pop();

        if (token == "+")
          stack.push(num2 + num1);
        if (token == "-")
          stack.push(num2 - num1);
        if (token == "*")
          stack.push(num2 * num1);
        if (token == "/")
          stack.push(num2 / num1);
      } else {
        stack.push(stoi(token));
      }
    }

    return stack.top();
  }
};
