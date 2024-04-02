/**
 * @brief Returns the top K freq elements.
 *
 * Approach:
 * Populate a map with how many times each element occurs. Translate these elements
 * into an array and sorts them based on the value of each key in the map.
 *
 * Time:
 * Populating map takes N time. Sort function takes Nlog(N). Plus time of map() which is N.
 */

function topKFrequent(nums: number[], k: number): number[] {
  const map: { [key: number]: number } = {};

  // Populate the map with how many times each number occurs.
  for (const num of nums)
    map[num]++;

  // Object.keys returns array of keys.
  // Sorts them, positive means swap, negative means no swap.
  const sorted = Object.keys(map).sort((a, b) => map[b] - map[a]);

  const ans: number[] = [];

  // Pushes the first k elements onto answer.
  for (let i = 0; i < k; i++)
    ans.push(parseInt(sorted[i]));

  return ans;
}

/**
 * @brief Approach using built-in Map instead of my own map object.
 */
function topKFrequentUsingMap(nums: number[], k: number): number[] {
  const hash = new Map<number, number>();

  for (const num of nums) {
    // hash.get returns the value or und.
    // If und, we set count to 0 + 1.
    // else count + 1.
    const count = (hash.get(num) || 0) + 1;
    hash.set(num, count);
  }

  const sorted: number[] =
    // Spreads notation to spread the interator to an array of [key, value]
    [...hash.entries()]
      // Sort from highest to lowest freq
      // keyA & keyB can be omitted
      .sort(([_keyA, valueA], [_keyB, valueB]) => valueB - valueA)
      // Populates the array with key instead of [key, value]
      // value doesn't need to be here but it's nice to visualize.
      .map(([key, _value]) => key);

  const ans: number[] = [];
  for (let i = 0; i < k; i++)
    ans.push(sorted[i]);

  return ans;
}
