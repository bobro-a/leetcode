#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        stack<int> s;
        int rez = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            if (!s.empty() && prices[i] < s.top())
            {
                int first = s.top();
                int last;
                while (!s.empty())
                {
                    last = s.top();
                    s.pop();
                }
                rez+=(first-last);
            }
            s.push(prices[i]);
        }
        if (!s.empty())
        {
            int first = s.top();
            int last;
            while (!s.empty())
            {
                last = s.top();
                s.pop();
            }
            rez+=(first-last);
        }
        return rez;
    }
};


int main()
{
    vector<int> prices = {7,6,4,3,1};
    Solution a;
    int rez = a.maxProfit(prices);
    return 0;
}
