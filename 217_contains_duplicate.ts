function containsDuplicate(nums: number[]): boolean {
  const map: {[key: number]: number } = {};

  for (const n of nums) {
    map[n] = map[n] ? map[n] + 1 : 1;
    if (map[n] > 1) return true;
  }

  return false;
};
