
function groupAnagrams(strs: string[]): string[][] {
  const answer: string[][] = [];
  const hash: { [key: string]: string[] } = {};

  for (const str of strs) {
    const sorted = str.split('').sort().join();
    if (!hash[sorted]) hash[sorted] = [];
    hash[sorted].push(str);
  }

  let set: string[];

  for (const key of Object.keys(hash)) {
    set = [];
    for (const str of hash[key]) {
      set.push(str);
    }
    answer.push(set);
  }

  return answer;
}
