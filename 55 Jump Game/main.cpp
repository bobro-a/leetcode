#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size()==1) return true;
        if (nums[0]==0) return false;
        vector<int> dp(nums.size(),0);
        for (int i=0;i<nums.size()-1;++i)
        {
            int jump=nums[i];
            while (jump!=0)
            {
                if (i+jump<nums.size()  )
                {
                    (dp[i]!=0 && i!=0 || i==0)?++dp[i+jump]:0;
                }
                --jump;
                if (dp[dp.size()-1]!=0)
                {
                    return true;
                }
            }
        }
        return false;
    }
};


int main()
{
    vector<int> prices = {2,3,1,1,4};
    Solution a;
    bool rez = a.canJump(prices);
    return 0;
}
