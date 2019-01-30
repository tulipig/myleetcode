class Solution:
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        n = len(matrix)-1 #行
        if n>=0:
            m = len(matrix[0])-1 #列
        else:
            return 0
         
        tb = set()
        i = 0
        while i<=n:
            j = 0
            while j<=m:
                if matrix[i][j] == "1":
                    tb.add((i,j))
                j += 1
            i += 1

        #print(tb)
        ans = 1 if len(tb) > 0 else 0
        for element in tb:
            i = element[0]
            j = element[1]
            #print("====", i , j)

            x = 1
            while i+1 <= n:
                if matrix[i+1][j] == "0":
                    break
                else:
                    x += 1
                    i += 1

            y = 1
            i = element[0]
            while j+1 <= m:
                if matrix[i][j+1] == "0":
                    break
                else:
                    y += 1
                    j += 1

            #print(element, x, y)     
            ans = max(ans, x*y)

        return ans




sol = Solution()
matrix = [
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
print(sol.maximalRectangle(matrix))
                