#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string rez="";
        for (int i=0;i<s.size();++i)
        {
            if (s[i]=='*' && !rez.empty())
                rez.erase(rez.size()-1);
            else if (s[i]!='*')
            {
                rez+=s[i];
            }
        }
        return rez;
    }
};


int main()
{
    string stroka = "leet**cod*e";
    Solution a;
    a.removeStars(stroka);
    return 0;
}
