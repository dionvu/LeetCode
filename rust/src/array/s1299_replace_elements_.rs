use crate::solution::Solution;

/**
* @date 2024-06-02
*/

#[allow(dead_code)]
impl Solution {
  pub fn replace_elements(arr: Vec<i32>) -> Vec<i32> {
    let mut arr = arr;

    for i in 0..arr.len() {
      if i == arr.len() - 1 {
        arr[i] = -1;
        break;
      }

      let mut biggest = arr[i + 1];
      for j in (i + 2)..arr.len() {
        biggest = biggest.max(arr[j]);
      }

      arr[i] = biggest;
    }

    arr
  }
}

#[test]
fn test() {}

// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/description/
