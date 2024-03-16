/**
 * @date 2024 March 14
 */

function merge(nums1: number[], m: number, nums2: number[], n: number): void {
  if (nums1.length === 0) nums1 = nums2;
  if (nums2.length === 0) return;

  let index1 = 0;
  let index2 = 0;
  let temp: number[] = [];

  while (index1 < m && index2 < n) {
    if (nums1[index1] < nums2[index2]) {
      temp.push(nums1[index1]);
      index1++;
    } else {
      temp.push(nums2[index2]);
      index2++;
    }
  }

  while (index1 < m) {
    temp.push(nums1[index1]);
    index1++;
  }

  while (index2 < n) {
    temp.push(nums2[index2]);
    index2++;
  }

  for (let i = 0; i < m + n; i++) {
    nums1[i] = temp[i];
  }
  nums1 = temp;
}
