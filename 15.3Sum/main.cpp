#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> rez;
        int l = 0, r = nums.size() - 1, sr = l + 1;
        while (nums[l]<=0 && r-l>1)
        {
            if (nums[l]+nums[sr]+nums[r]==0)
            {
                rez.push_back({nums[l],nums[sr],nums[r]});
                ++sr;
            }else if (nums[l]+nums[sr]+nums[r]<0)
            {
                ++sr;
            }
            else{
                --r;
            }
            if (sr==r)
            {
                ++l;
                sr=l+1;
                r=nums.size()-1;
            }
        }
        set<vector<int>> s( rez.begin(), rez.end() );
        rez.assign( s.begin(), s.end() );
        return rez;
    }
};


int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    Solution a;
    vector<vector<int>> rez = a.threeSum(nums);
    return 0;
}
