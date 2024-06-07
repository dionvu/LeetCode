use crate::solution::Solution;

/**
* @date 2024-06-04
*/

#[allow(dead_code)]
impl Solution {
  pub fn length_of_last_word(s: String) -> i32 {
    let s: Vec<String> = s
      .split_whitespace()
      .map(|str| str.to_string())
      .collect();

    if s.is_empty() {
      return 0;
    }

    s.last().unwrap().len() as i32
  }
}

#[test]
fn test() {}

// https://leetcode.com/problems/length-of-last-word/description/

/*
impl Solution {
  pub fn length_of_last_word(s: String) -> i32 {
    let mut ans = 0;
    for c in s.chars().rev() {
      if c != ' ' {
        ans += 1;
      } else {
        if 0 < ans {
          return ans;
        }
      }
    }
    ans
  }
}
*/
