#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

class Solution
{
public:
    int equalPairs(vector<vector<int>>& grid)
    {
        int rez = 0;
        int n = grid.size();
        map <vector<int>,int> m;
        for (int i=0;i<n;++i)
        {
            ++m[grid[i]];
        }
        for (int i=0;i<n;++i)
        {
            vector<int> temp;
            for (int j=0;j<n;++j)
            {
                temp.push_back(grid[j][i]);
            }
            rez+=m[temp];
            temp.clear();
        }
        return rez;
    }
};


int main()
{
    vector<vector<int>> grid = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
    Solution a;
    int rez = a.equalPairs(grid);
    cout << rez << endl;
    return 0;
}
