#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
struct xyC
{
    xyC(int x,int y)
    {
        this->x=(char)(x+int('0'));
        this->y=(char)(y+int('0'));
        if (0<=x && x<=2)
        {
            if (0<=y && y<=2) this->C='1';
            else if (3<=y && y<=5) this->C='4';
            else if (6<=y && y<=8) this->C='7';
        }else if (3<=x && x<=5)
        {
            if (0<=y && y<=2) this->C='2';
            else if (3<=y && y<=5) this->C='5';
            else if (6<=y && y<=8) this->C='8';
        }else if (6<=x && x<=8)
        {
            if (0<=y && y<=2) this->C='3';
            else if (3<=y && y<=5) this->C='6';
            else if (6<=y && y<=8) this->C='9';
        }
    };
    char x;
    char y;
    char
    C;
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        multimap<char,xyC> m;
        for (int i=0;i<board.size();++i)
        {
            for (int j=0;j<board[i].size();++j)
            {
                if (board[i][j]=='.') continue;
                if (m.count(board[i][j])==0)
                {
                    m.emplace(board[i][j],xyC(i,j));
                }else
                {
                    xyC temp(i,j);
                    auto it2=m.upper_bound(board[i][j]);
                    for (auto it=m.lower_bound(board[i][j]);it!=it2;++it)
                    {
                        if (temp.x==it->second.x || temp.y==it->second.y || temp.C==it->second.C)
                        {
                            return false;
                        }
                    }
                    m.emplace(board[i][j],temp);
                }
            }
        }
        return true;
    }
};


int main()
{
    vector<vector<char>> board={{'5','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                            {'.','9','8','.','.','.','.','6','5'},
                            {'8','.','.','.','6','.','.','.','3'},
                            {'4','.','.','8','.','3','.','.','1'},
                            {'7','.','.','.','2','.','.','.','6'},
                            {'.','6','.','.','.','.','2','8','.'},
                            {'.','.','.','4','1','9','.','.','.'},
                            {'9','.','.','.','8','.','.','7','9'}};
    Solution a;
    bool rez = a.isValidSudoku(board);
    cout << rez << endl;
    return 0;
}
