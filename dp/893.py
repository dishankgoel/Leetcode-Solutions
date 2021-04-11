class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        a, curr = set(), set()
        for i in arr:
            curr = {i | x for x in curr} | {i}
            a |= curr
        return len(a)