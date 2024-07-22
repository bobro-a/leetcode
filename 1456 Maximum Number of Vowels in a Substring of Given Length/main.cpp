#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

//'a', 'e', 'i', 'o', and 'u'.
class Solution
{
public:
    int maxVowels(string s, int k)
    {
        vector<int> prefsum(s.size() + k,0);
        int maxEl = 0;
        for (int i = s.size() - 1; i >= 0; --i)
        {
                prefsum[i] = prefsum[i + 1] +isVowel(s[i]);
        }
        for (int i = s.size() - 1; i >= 0; --i)
        {
            maxEl=max(prefsum[i]-prefsum[i+k],maxEl);
        }
        return maxEl;
    }
    bool isVowel(char symbol)
    {
         return (symbol == 'a' || symbol == 'e' || symbol == 'i' || symbol == 'o' || symbol == 'u');
    }
};


int main()
{
    string s = "abciiidef";
    Solution a;
    int rez = a.maxVowels(s, 3);
    return 0;
}
