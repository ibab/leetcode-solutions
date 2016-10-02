class Solution(object):
    def longestPalindrome(self, s):
        from collections import Counter
        c = Counter(s)
        useful = 0
        for ch, count in c.items():
            useful += count // 2
        return 2 * useful + (1 if 2 * useful < len(s) else 0)
