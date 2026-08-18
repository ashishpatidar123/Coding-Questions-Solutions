class Solution:
    def minimumOperations(self, nums: List[int], target: List[int]) -> int:
        n = len(nums)
        res = 0
        prev = 0

        for i in range(n):
            curr = nums[i] - target[i]

            if (curr > 0 and prev < 0) or (curr < 0 and prev > 0):
                res += abs(curr)
            elif abs(curr) - abs(prev) > 0:
                res += abs(curr - prev)

            prev = curr

        return res

        
