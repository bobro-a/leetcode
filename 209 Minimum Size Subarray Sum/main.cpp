#include <algorithm>
#include <climits>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int N=nums.size();
        int minLen=INT_MAX;
        vector<int> prefsum(N+1,0);
        for (int i=0;i<N;++i)
        {
            prefsum[i+1]=prefsum[i]+nums[i];
        }
        int i=0;int j=1;
        while (i<N)
        {
            if (prefsum[j]-prefsum[i]>=target)
            {
                minLen=min(minLen,j-i);
                if (minLen==1)
                {
                    return 1;
                }
                ++i;
            }else if(j<N)
            {
                ++j;
            }
            else break;

        }
        if (minLen==INT_MAX) return 0;
        else return minLen;

    }
};


int main()
{
    int target = 11;
    vector<int> v= {1,1,1,1,1,1,1};
    Solution a;
    int rez = a.minSubArrayLen(target,v);
    return 0;
}
