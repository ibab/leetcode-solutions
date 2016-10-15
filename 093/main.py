
class Solution(object):

  def _generate(self, s):
    for i in range(1, 4):
      for j in range(i+1, i+4):
        for k in range(j+1, j+4):
          if len(s) - k in (1, 2, 3):
            a = s[:i]
            b = s[i:j]
            c = s[j:k]
            d = s[k:]
            if any(x.startswith('0') and not x == '0'
                   for x in (a, b, c, d)):
              continue
            if any(int(x) > 255
                   for x in (a, b, c, d)):
              continue
            yield "{}.{}.{}.{}".format(a, b, c, d)

  def restoreIpAddresses(self, s):
    return list(self._generate(s))

if __name__ == '__main__':
    print(Solution().restoreIpAddresses("123123045"))
