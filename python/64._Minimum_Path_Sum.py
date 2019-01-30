class Solution:
    def minPathSum(self, grid):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        n = len(grid) - 1 #行
        if n >= 0:
            m = len(grid[0]) - 1  #列
        else:
            return 0

        tb = {}
        tb[(0,0)] = grid[0][0]
        i = j = 1
        while i <= n:
            tb[(i,0)] = tb[(i-1,0)] + grid[i][0]
            i += 1
        while j <= m:
            tb[(0,j)] = tb[(0,j-1)] + grid[0][j]
            j += 1

        x = 1
        while x <= n:
            y = 1
            while y <= m:
                tb[(x,y)] = min(tb[(x-1,y)] , tb[(x,y-1)]) + grid[x][y]
                y += 1
            x += 1

        #print(tb)
        return tb[(n,m)]

sol = Solution()
#grid = [ [0,0,0], [0,1,0], [0,0,0] ]
#grid = [[0, 0]]
grid = [
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
print(sol.minPathSum(grid))