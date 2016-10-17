class Solution(object):
    def wordPattern(self, pattern, str):
        d = dict()
        e = dict()
        if (len(pattern) != len(str.split())):
            return False
        for p, w in zip(pattern, str.split()):
            if p in d and d[p] != w:
                return False
            if w in e and e[w] != p:
                return False
            d[p] = w
            e[w] = p
        return True
