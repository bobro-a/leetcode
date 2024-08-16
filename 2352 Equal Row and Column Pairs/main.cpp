#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int equalPairs(vector<vector<int>>& grid)
    {
        int rez = 0;
        int n = grid.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {

                int countEqual = 0;
                if (grid[i][0] == grid[0][j])
                {
                    for (int z = 0; z < n; ++z)
                    {
                        if (grid[i][z] == grid[z][j]) ++countEqual;
                        else break;
                    }
                    if (countEqual == n) ++rez;
                }
            }
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
