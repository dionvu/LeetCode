/**
 * Finds the top k most frequent numbers in nums.
 * @date 2024 March 15
 */

function topKFrequent(nums: number[], k: number): number[] {
  const map: { [key: number]: number } = {};
  const answer: number[] = [];

  for (const n of nums)
    map[n] = map[n] ? map[n] + 1 : 1;

  // Sorts the keys of map into an array
  const sortedKeys: string[] = Object.keys(map).sort((a, b) => map[b] - map[a]);

  for (let i = 0; i < k; i++)
    answer.push(parseInt(sortedKeys[i]));

  return answer;
};
