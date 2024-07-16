#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int first=0,second;
        if (nums.size()==1)
        {
            return 0;
        }else second=1;
        int count=0;
        while(first<nums.size()-1)
        {
            if (nums[first]+nums[second]==k)
            {
                auto it1=nums.begin()+first;
                auto it2=nums.begin()+second;
                nums.erase(it2);
                nums.erase(it1);
                ++count;
                if (nums.size()>=2)
                {
                    first=0;
                    second=1;
                }
                else return count;

            }
            else if (second==nums.size()-1)
            {
                ++first;
                second=++first;
            }
            else
            {
                ++second;
            }
        }
        return count;
    }
};
int main()
{
    vector <int> n={12};
    Solution a;
    cout<<a.maxOperations(n,12)<<endl;
    return 0;
}