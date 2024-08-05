#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        sort(citations.begin(), citations.end());
        int rez=0;
        for (int i=0;i<n;++i)
        {
            if (citations[i]<=n-i) rez=max(citations[i],rez);
            else
            {
                rez=max(n-i,rez);
                break;
            }
        }
        return rez;
    }
};


int main()
{
    vector<int> citations = {0};
    Solution a;
    int rez = a.hIndex(citations);
    cout<<rez<<endl;
    return 0;
}
