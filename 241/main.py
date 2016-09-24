import re

class Solution(object):
    def diffWaysToCompute(self, input):
        # Parse string into numbers and operators
        nums = list(map(int, re.split('[\+\-\*]', input)))
        ops = list(filter(lambda x: x in ['+', '-', '*'], input))

        # If this is a leaf, we just return the number
        if not ops:
            return [nums[0]]

        result = []
        # Divide and conquer: Calculate left and right expression and combine results
        for i in range(len(ops)):
            left = self.diffWaysToCompute(self.encode(nums[:i + 1], ops[:i]))
            right = self.diffWaysToCompute(self.encode(nums[i + 1:], ops[i + 1:]))

            for l in left:
                for r in right:
                    if ops[i] == '+':
                        result.append(l + r)
                    elif ops[i] == '-':
                        result.append(l - r)
                    elif ops[i] == '*':
                        result.append(l * r)

        return sorted(result)

    def encode(self, nums, ops):
        output = []
        for a, b in zip(nums, ops):
            output.append(str(a) + b)
        return ''.join(output) + str(nums[-1])

if __name__ == '__main__':
    print(Solution().diffWaysToCompute('1 + 2 - 3 * 4 + 2'))
