use crate::solution::Solution;

/**
* @date 2024-06-05
*/
#[allow(dead_code)]
impl Solution {
  pub fn can_place_flowers(flowerbed: Vec<i32>, n: i32) -> bool {
    let mut flower_bed = flowerbed;
    let mut flowers_left = n;
    let len = flower_bed.len();

    if len == 0 {
      return flowers_left == 0;
    }

    for i in 0..len {
      if flower_bed[i] == 0
        && (i == 0 || flower_bed[i - 1] == 0)
        && (i == len - 1 || flower_bed[i + 1] == 0)
      {
        flower_bed[i] = 1;
        flowers_left -= 1;
        if flowers_left <= 0 {
          return true;
        }
      }
    }

    flowers_left <= 0
  }
}

#[test]
fn test() {}

// https://leetcode.com/problems/can-place-flowers/description/
