#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        int start = 0;
        int sumtemp = 0;
        for(int idx=1; idx<height.size(); ++idx){
            if(height[idx]<height[start]){
                sumtemp += (height[start]-height[idx]);
            }
            else if(height[idx]>=height[start]){
                start = idx;
                sum += sumtemp;
                sumtemp = 0;
            }
        }

        int nevstart = height.size()-1;
        sumtemp = 0;
        for(int idx=nevstart; idx>=start; --idx)
        {
            if(height[idx]<height[nevstart]){
                sumtemp += (height[nevstart]-height[idx]);
            }
            else if(height[idx]>=height[nevstart]){
                nevstart = idx;
                sum += sumtemp;
                sumtemp = 0;
            }
        }

        return sum;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution sol;
    cout << sol.trap(v) << endl;
    return 0;
}