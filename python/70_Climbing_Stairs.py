class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = {}
        ans[1] = 1
        ans[2] = 2
        x = 3
        while x <= n :
            ans[x] = ans[x-1] + ans[x-2]
            x += 1

        return ans[n]

sol = Solution()
print(sol.climbStairs(4))
