#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int lenght=0;
        int left=0;
        unordered_set<char> charSet;
        for (int right=0;right<n;++right)
        {
            if (charSet.count(s[right])==0)
            {
                charSet.insert(s[right]);
                lenght=max(lenght,right-left+1);
            }else
            {
                while (charSet.count(s[right]))
                {
                    charSet.erase(s[left]);
                    ++left;
                }
                charSet.insert(s[right]);
            }
        }
        return lenght;
    }
};


int main()
{
    string s= "pwwkew";
    Solution a;
    int rez = a.lengthOfLongestSubstring(s);
    return 0;
}
