// #include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <iostream>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int>& nums)
    {
        int i = 0, j = 0, k = 1, rez = 0;
        if (nums.size() == 1) return 0;
        while (j < nums.size())
        {
            if (k == 0 && nums[j] == 0)
            {
                rez = max(rez, j - i - 1);
                if (nums[i] == 0)
                {
                    ++k;
                }
                ++i;
                continue;
            }
            if (nums[j] == 0) --k;

            ++j;
        }

        return max(rez, j - i - 1);
    }
};


int main()
{
    vector<int> nums = {0,0,0,1,0,1,0};
    Solution a;
    int rez = a.longestSubarray(nums);
    cout << rez << endl;
    return 0;
}
