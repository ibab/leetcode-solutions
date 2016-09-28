class Solution(object):
    def romanToInt(self, s):
        roman = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        result = 0
        for x, y in zip(s, s[1:]):
            if roman[x] < roman[y]:
                result -= roman[x]
            else:
                result += roman[x]
        result += roman[s[-1]]
        return result
