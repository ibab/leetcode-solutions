# Problem 7 - Reverse Integer
#
# Reverse digits of an integer.
#
# Example1: x = 123, return 321
# Example2: x = -123, return -321


# Python makes this extremely easy
class Solution(object):
    def reverse(self, x):
        y = int(str(abs(x))[::-1])
        # This doesn't overflow with Python 3, but we need to fulfill the
        # solution's weird requirement to set the output to 0 if we overflow a
        # 32 bit signed integer.
        if y > 2**31:
            y = 0
        if x < 0:
            y *= -1
        return y
