# Problem 6 - ZigZag Conversion
#
# The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
# of rows like this: (you may want to display this pattern in a fixed font for
# better legibility)
# 
# P   A   H   N
# A P L S I I G
# Y   I   R
#
# And then read line by line: "PAHNAPLSIIGYIR"
# Write the code that will take a string and make this conversion given a number of rows:
#
#   string convert(string text, int nRows);
#
# convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

class Solution(object):
    # The zigzag patter consists of segments of size 2 * numRows - 2.
    # The idea to split the iteration into two loops:
    # The outer loop steps through possible offsets into the segment
    # The inner loop steps through segments
    # Inside the inner loop, we add neighbouring elements (read out in
    # reverse from the end of the segment) if we are not at the first or last
    # step of the outer iteration.
    def convert(self, s, numRows):
        if numRows == 1:
            return s

        blockSize = 2 * numRows - 2

        out = ''
        for idx1 in range(0, numRows):
            for idx2 in range(0, len(s), blockSize):
                first = idx1 + idx2
                if first >= len(s):
                    break
                out += s[first]
                second = blockSize + idx2 - idx1
                if second >= len(s):
                    # We're at the end of the pattern and
                    # there are no more characters
                    break
                if idx1 not in (0, numRows - 1):
                    # We're not at the first or last element
                    # of a segment, so there's a partner element
                    out += s[second]

        return out

if __name__ == '__main__':
    print(Solution().convert('ABCDE', 4))

