#include <vector>
#include <iostream>
#include <string>
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
                    string stroka = to_string(count);
                    for (auto i : stroka)
                    {
                        newChars.push_back(i);
                    }
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
                    string stroka = to_string(count);
                    for (auto i : stroka)
                    {
                        newChars.push_back(i);
                    }
                }
            }
        }
        chars.assign(newChars.begin(), newChars.end());
        return chars.size();
    }
};

int main()
{
    vector<char> chars = {'a', 'b', 'b', 'b', 'c', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    Solution a;
    cout << a.compress(chars) << endl;
    for (auto i : chars)
    {
        cout << i << endl;
    }
    return 0;
}
