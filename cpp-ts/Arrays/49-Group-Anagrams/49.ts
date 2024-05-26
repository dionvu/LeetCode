function groupAnagrams(strs: string[]): string[][] {
  const hash: { [key: string]: string[] } = {};

  for (const str of strs) {
    const sorted = str.split('').sort().join();
    if (!hash[sorted]) hash[sorted] = [];
    hash[sorted].push(str);
  }

  return Object.values(hash);
}
