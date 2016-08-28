from collections import Counter

class Solution(object):
    def findTheDifference(self, s, t):
        c1 = Counter(s)
        c2 = Counter(t)
        for letter, count in c2.items():
            if letter not in c1 or count != c1[letter]:
                return letter
if __name__ == '__main__':
    s = "abcd"
    t = "abcde"
    print(Solution().findTheDifference(s, t))
