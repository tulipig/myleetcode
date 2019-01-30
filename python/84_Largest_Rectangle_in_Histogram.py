class Solution:
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        #sortHeights = sorted(heights)
        ans = 0

        for sorthg in heights:
            span = 0
            localSpan = 0
            for hg in heights:
                if hg - sorthg >= 0:
                    localSpan += 1
                    if localSpan > span:
                        span = localSpan
                else:
                    localSpan = 0

            ans = max(ans, span * sorthg)

        return ans

sol = Solution()
print(sol.largestRectangleArea([2,1,5,6,2,3]))

