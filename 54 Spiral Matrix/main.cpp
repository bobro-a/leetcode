#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> rez;
        int top=0,bottom=matrix.size()-1,left=0,right=matrix[0].size()-1;
        while (top<=bottom && left<=right)
        {
            for (int i=left;i<=right;++i)
            {
                rez.push_back(matrix[top][i]);
            }
            ++top;
            for (int i=top;i<=bottom;++i)
            {
                rez.push_back(matrix[i][right]);
            }
            --right;
            if (top<=bottom)
            {
                for (int i=right;i>=left;--i)
                {
                    rez.push_back(matrix[bottom][i]);
                }
                --bottom;
            }
            if (left<=right)
            {
                for (int i=bottom;i>=top;--i)
                {
                    rez.push_back(matrix[i][left]);
                }
                ++left;
            }
        }
        return rez;
    }
};


int main()
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    Solution a;
    a.spiralOrder(matrix);
    return 0;
}
