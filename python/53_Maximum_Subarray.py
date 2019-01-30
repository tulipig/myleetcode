class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = prev_globle = nums[0]
        prev_local = 0
        i = 0
        while i < len(nums):
            local = max(prev_local + nums[i], nums[i])
            ans = max(prev_globle, local)

            prev_local = local
            prev_globle = ans

            i += 1

        return ans


sol = Solution()
max = sol.maxSubArray([-2,1,-3,4,-1,2,1,-5,4])
#max = sol.maxSubArray([1])
print(max)