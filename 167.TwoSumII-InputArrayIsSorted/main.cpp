#include <vector>
#include <map>
#include <iostream>
#include <string>
using namespace std;


class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> rez;
        int r=0,l=numbers.size()-1;
        while (numbers[r]+numbers[l]!=target)
        {
            if (numbers[r]+numbers[l]>target)
            {
                --l;
            }
            if (numbers[r]+numbers[l]<target)
            {
                ++r;
            }
        }
        rez.push_back(r+1);
        rez.push_back(l+1);
        return rez;
    }
};

int main()
{
    vector<int> num = {2,3,4};
    Solution a;
    vector<int> rez = a.twoSum(num, 6);
    return 0;
}
