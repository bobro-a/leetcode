#include <vector>
#include <set>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> parent;
    int findParent(int x)
    {
        if (parent[x]==x)
        {
           return x;
        }else
        {
            return findParent(parent[x]);
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> rezult(2,0);
        int n=edges.size();
        parent.resize(n+1,0);
        for (int i=0;i<=n;++i)
        {
            parent[i]=i;
        }
        for (int i=0;i<n;++i)
        {
            int first=findParent(edges[i][0]);
            int second=findParent(edges[i][1]);
            if (first!=second)
            {
                parent[second]=first;
            }else
            {
                rezult[0]=edges[i][0];
                rezult[1]=edges[i][1];
            }
        }
        return rezult;
    }
};

int main()
{
    vector<vector<int>> edges = {
        {1,2},{2,3},{3,4},{1,4},{1,5}
    };
    Solution a;
    vector<int> res = a.findRedundantConnection(edges);
    return 0;
}
