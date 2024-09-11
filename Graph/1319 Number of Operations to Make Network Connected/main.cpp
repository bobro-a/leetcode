#include <vector>
#include <iostream>
#include <pstl/execution_defs.h>
using namespace std;


class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int findParent(int v)
    {
        if (parent[v]==v)
        {
            return v;
        }else return findParent(parent[v]);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int rez=0;
        int m=connections.size();
        if (m<n-1)
        {
            return -1;
        }
        parent.resize(n);
        rank.resize(n,0);
        for (int i=0;i<n;++i)
        {
            parent[i]=i;
        }

        for (int i=0;i<m;++i)
        {
            int x=findParent(connections[i][0]);
            int y=findParent(connections[i][1]);
            if (x!=y)
            {
                if (rank[x]<rank[y])
                {
                    parent[x]=y;
                }else if(rank[x]>rank[y])
                {
                    parent[y]=x;
                }else
                {
                    parent[y]=x;
                    ++rank[x];
                }
                ++rez;
            }
        }
        return n-rez-1;
    }
};

int main()
{
    vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2},{1,3}};
    Solution a;
    int rez = a.makeConnected(6,connections);
    cout<<rez<<endl;
    return 0;
}
