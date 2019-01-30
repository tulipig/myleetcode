class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        n = len(obstacleGrid) - 1 #行
        if n >= 0:
            m = len(obstacleGrid[0]) - 1  #列
        else:
            return 0

        tb = {}
        if obstacleGrid[0][0] == 1:
            return 0
        else:
            tb[(0,0)] = 1

        i = j = 0
        while i <= n:
            tb[(i,0)] = 1 if obstacleGrid[i][0] == 0 else 0
            if i>=1 and tb[(i-1,0)] == 0:
                tb[(i,0)] = 0
            i += 1
        while j <= m:
            tb[(0,j)] = 1 if obstacleGrid[0][j] == 0 else 0
            if j>=1 and tb[(0,j-1)] == 0:
                tb[(0,j)] = 0
            j += 1

        x = 1
        while x <= n:
            y = 1
            while y <= m:
                if obstacleGrid[x][y] == 0:
                    tb[(x,y)] = tb[(x-1,y)] + tb[(x,y-1)]
                else:
                    tb[(x,y)] = 0
                y += 1
            x += 1

        print(tb)
        return tb[(n,m)]

sol = Solution()
#obstacleGrid = [ [0,0,0], [0,1,0], [0,0,0] ]
#obstacleGrid = [[0, 0]]
obstacleGrid = [[0,1,0,0,0],[1,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0]]
print(sol.uniquePathsWithObstacles(obstacleGrid))