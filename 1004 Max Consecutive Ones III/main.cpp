#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int rez=0;
        int iM=0,jM=0;
        while(j<nums.size())
        {
            if (nums[j]==0)
            {
                --k;
            }
            if (k<0)
            {
                if (j-i>rez)
                {
                    iM=i;
                    jM=j;
                    rez=j-i;
                }
                if (nums[i]==0)
                {
                    ++k;
                }
                ++i;
            }
            ++j;
        }
        if (j-i>rez)
        {
            iM=i;
            jM=j;
            rez=j-i;
        }
        for (int i=iM;i<jM;++i)
        {
            nums[i]=1;
        }
        return rez;
    }
};


int main()
{
    vector<int> s = {0,0,0,1};
    Solution a;
    cout<<a.longestOnes(s, 4)<<endl;
    cout<<endl;
    for (int i:s)
    {
        cout<<i<<"\t";
    }
    return 0;
}
