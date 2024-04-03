/**
 * @date 2024 Apr 03
 *
 * Approach:
 * Use a stack to keep track of the opening brackets, if we have a closing
 * bracket, check that the top of the stack is the matching bracket, if not, we
 * return false. Makes sure to return if the stack is empty at the end.
 *
 * Time:
 * Find takes constant time, and we go through each character of s only once.
 * O(N)
 */

#include <algorithm>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {

    // Used to keep track of only the opening brackets.
    stack<char> stack;

    const char opening[] = {'(', '{', '['};

    for (const char c : s) {

      // Handles opening brackets
      if (find(begin(opening), end(opening), c) != end(opening)) {
        stack.push(c);
      }

      // Handles closing bracket
      else {

        // If the stack is empty there is no possible matching opening bracket.
        if (stack.empty())
          return false;

        // Equivalates matching bracket if they match we pop stack.top().
        if (c == ')' && stack.top() != '(')
          return false;
        else if (c == ']' && stack.top() != '[')
          return false;
        else if (c == '}' && stack.top() != '{')
          return false;
        else
          stack.pop();
      }
    }

    // Don't return true because it is possible we still have remaining opening
    // brackets on the stack.
    return stack.empty();
  }
};
