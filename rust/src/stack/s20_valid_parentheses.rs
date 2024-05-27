use crate::solution::Solution;

/**
* @date 2024-05-26
*/

#[allow(dead_code)]
impl Solution {
  pub fn is_valid(s: String) -> bool {
    let mut stack: Vec<char> = Vec::with_capacity(s.len());

    for c in s.chars() {
      match c {
        '{' | '(' | '[' => stack.push(c),
        _ => match stack.pop() {
          Some('(') => {
            if c != ')' {
              return false;
            }
          }
          Some('[') => {
            if c != ']' {
              return false;
            }
          }
          Some('{') => {
            if c != '}' {
              return false;
            }
          }
          _ => return false,
        },
      }
    }

    stack.is_empty()
  }
}

#[test]
fn test() {
  assert_eq!(Solution::is_valid("()[]".to_string()).to_string(), "true");
  assert_eq!(Solution::is_valid("([{}])".to_string()).to_string(), "true");
  assert_eq!(
    Solution::is_valid("(())[{}]".to_string()).to_string(),
    "true"
  );
}

// https://leetcode.com/problems/valid-parentheses/
