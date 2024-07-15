#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;


class Solution
{
public:
    int compress(vector<char>& chars)
    {
        int count = 0;
        vector<char> newChars;
        for (int i = 0; i < chars.size(); ++i)
        {
            if (i == 0)
            {
                ++count;
            }
            else if (chars[i] != chars[i - 1])
            {
                newChars.push_back(chars[i - 1]);
                if (count != 1)
                {
                    if (count > 9)
                    {
                        for (int j=0;j<to_string(count).size();++j)
                        {
                            newChars.push_back(to_string(count)[i]);
                        }
                    }
                    else
                        newChars.push_back(count);
                }
                count = 1;
            }
            else
            {
                ++count;
            }
            if (i == (chars.size() - 1))
            {
                newChars.push_back(chars[i]);
                if (count != 1)
                {
                    if (count > 9)
                    {
                        for (int j=0;j<to_string(count).size();++j)
                        {
                            newChars.push_back(char(to_string(count)[i]));
                        }
                    }
                    else
                        newChars.push_back(count);
                }
            }
        }
        chars.assign(newChars.begin(), newChars.end());
        newChars.clear();
        return newChars.size();
    }
};

int main()
{
    vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    Solution a;
    cout << a.compress(chars) << endl;
    return 0;
}
