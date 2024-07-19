#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        int l=0,r=height.size()-1;
        while (l<r)
        {
            maxArea=max(maxArea,min(height[r],height[l])*(r-l));
            if (height[r]<height[l])
            {
                --r;
            }
            else
            {
                ++l;
            }
        }
        return maxArea;
    }
};


int main()
{
    vector<int> height={1,8,6,2,5,4,8,3,7};
    Solution a;
    cout<<a.maxArea(height)<<endl;
    return 0;
}
