class Solution(object):
    def partition(self, s):
        if not s:
            return [[]]
        r = s[::-1]
        result = []
        for i in range(1, len(r) + 1):
            if s.startswith(r[-i:]):
                print(s[:i])
                sub = self.partition(s[i:])
                result += [[s[:i]] + l for l in sub]
        return result

