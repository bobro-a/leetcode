#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int jumps = 0;
        int current_end = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + nums[i]);
            if (i == current_end) {
                jumps++;
                current_end = farthest;
                if (current_end >= n - 1) break;
            }
        }

        return jumps;
    }
};


int main()
{
    vector<int> prices = {2,3,1,1,4};
    Solution a;
    bool rez = a.jump(prices);
    return 0;
}
