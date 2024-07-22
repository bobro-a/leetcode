#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int temp = nums[0], count = 0, k = 0;
        for (auto it = nums.begin(); it < nums.end();)
        {
            if (*it == temp)
            {
                ++count;
                if (count > 2)
                {
                    nums.erase(it);
                    continue;
                }
            }
            else
            {
                k += (count>2)?2:count;
                temp = *it;
                count = 1;
            }
            ++it;
        }
        k += (count>2)?2:count;
        return k;
    }
};



int main()
{
    vector<int> nums = {1,1,1,2,2,3};
    Solution a;
    int rez = a.removeDuplicates(nums);
    return 0;
}
