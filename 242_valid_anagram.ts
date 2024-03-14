/**
 * @date 2024 March 13
 */


function isAnagram(s: string, t: string): boolean {
  if (s.length !== t.length) return false;

  let hash: { [key: string]: number } = {};

  for (const char of s)
    hash[char] = (hash[char] || 0) + 1;

  for (const char of t) {
    if (!hash[char]) return false;
    hash[char]--;
  }

  return true;
}
