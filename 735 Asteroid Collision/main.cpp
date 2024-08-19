#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> rez;
        for (int i=0;i<asteroids.size();++i)
        {
            if (asteroids[i]<0)
            {
                int j=rez.size()-1;
                    while (j>-1 && rez[j]>0)
                    {
                        if (rez[j]>abs(asteroids[i])) break;
                        else if (rez[j]==abs(asteroids[i]))
                        {
                            rez.pop_back();
                            break;
                        }
                        else
                        {
                            rez.pop_back();
                        }
                        --j;
                    }
                if (j==-1 || rez[j]<0) rez.push_back(asteroids[i]);
            }else
            {
                rez.push_back(asteroids[i]);
            }
        }
        return rez;
    }
};


int main()
{
    vector<int> asteroids={10,2,-5};
    Solution a;
    a.asteroidCollision(asteroids);
    return 0;
}
