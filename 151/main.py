class Solution(object):
    def reverseWords(self, s):
        return ' '.join(s.split()[::-1])

