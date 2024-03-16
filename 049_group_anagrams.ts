/**
 * @date 2024 March 14
 */

function groupAnagrams(strs: string[]): string[][] {
  const map: { [key: string]: string[] } = {};

  for (const string of strs) {
    const key: string = string.split('').sort((a: string, b: string) => {
      if (a > b) return -1;
      else return 1;
    }).join('');

    if (!map[key]) map[key] = [];
    map[key].push(string);
  }
  return Object.values(map);
}
