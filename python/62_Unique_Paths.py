class Solution:
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        tb = {}
        i = j = 0
        while i <= m:
            tb[(i,0)] = 1
            tb[(i,1)] = 1
            i += 1
        while j <= n:
            tb[(0,j)] = 1
            tb[(1,j)] = 1
            j += 1

        x = 2
        while x <= m:
            y = 2
            while y <= n:
                tb[(x,y)] = tb[(x-1,y)] + tb[(x,y-1)]
                y += 1
            x += 1

        #print(tb)
        return tb[(m,n)]

    #Time Limit Exceeded
    def uniquePaths_2(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        if m <= 1 or n <= 1:
            return 1
        else:
            return self.uniquePaths_2(m-1,n) + self.uniquePaths_2(m,n-1)


sol = Solution()
print(sol.uniquePaths_2(7,3))