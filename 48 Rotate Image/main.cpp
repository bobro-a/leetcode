#include <algorithm>
#include <iostream>
using namespace std;

struct xY
{
    int x,y;

};
class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int n=matrix.size();
            xY topL={0,0};
            xY  topR={0,n-1};
            xY  bottomL={n-1,0};
            xY  bottomR={n-1,n-1};
            while (topL.y<bottomR.y && bottomR)
            {
                while (count < n-1)
                {
                    swap(matrix[topL.x][topL.y],matrix[topR.x][topR.y]);
                    swap(matrix[topL.x][topL.y],matrix[bottomR.x][bottomR.y]);
                    swap(matrix[topL.x][topL.y],matrix[bottomL.x][bottomL.y]);
                    ++topL.x;
                    ++topR.y;
                    --bottomR.x;
                    --bottomL.y;
                }
            }
        }
    };


int main()
{
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    Solution a;
    a.rotate(matrix);
    return 0;
}
