from collections import Counter

class Solution(object):
    def topKFrequent(self, nums, k):
        return map(lambda x: x[0], Counter(nums).most_common(k))

