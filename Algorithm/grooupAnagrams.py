from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram_map = {}
        for s in strs:
            anagram_key = "".join(sorted(s))

            value = anagram_map.get(anagram_key, None)
            if value is None:
                anagram_map[anagram_key] = [s]
            else:
                anagram_map[anagram_key].append(s)
                
        return list(anagram_map.values())


s_instance = Solution()
print(s_instance.groupAnagrams(["a"]))
