use crate::solution::Solution;

/**
* @date 2024-05-28
*/

#[allow(dead_code)]
impl Solution {
  pub fn str_str(haystack: String, needle: String) -> i32 {
    let len = needle.len();

    if haystack == needle {
      return 0;
    }

    if len > haystack.len() {
      return -1;
    }

    let mut idx = 0;

    // + 1 fixes stopping before last possible string
    while idx < haystack.len() - len + 1 {
      let slice = &haystack[idx..idx + len];
      if *slice == needle {
        return idx as i32;
      }
      idx += 1;
    }
    -1
  }
}

#[test]
fn test() {
  assert_eq!(Solution::str_str("hello".to_string(), "ll".to_string()), 2);
}

//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
