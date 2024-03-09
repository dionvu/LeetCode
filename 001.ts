function twoSum(nums: number[], target: number): number[] {
  for (let i = 0; i < nums.length; i++) {
    for (let j = i + 1; j < nums.length; j++) {
      if ((nums[i] + nums[j]) === target) return [i, j];
    }
  }
  return [];
}

alert(twoSum([1, 2, 4, 5, 10], 5));
