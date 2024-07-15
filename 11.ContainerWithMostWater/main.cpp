#include <vector>
#include <iostream>
using namespace std;
//чужое решение с указателями (лучше по времени)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int currentArea = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, currentArea);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};
//моё
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int max_area=0;;
//         for (int i=0;i<height.size();++i)
//         {
//             for (int j=i+1;j<height.size();++j)
//             {
//                 max_area=max(max_area,min(height[i],height[j])*(j-i));
//             }
//         }
//         return max_area;
//     }
// };

int main()
{
    vector<int> height={1,8,6,2,5,4,8,3,7};
    Solution a;
    cout<<a.maxArea(height)<<endl;
    return 0;
}
