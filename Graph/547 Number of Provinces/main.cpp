#include <vector>
#include <set>
#include <iostream>
using namespace std;


class Solution
{
public:
    void DFS(int m, int n, vector<vector<int>>& isConnected, vector<bool>& visited)
    {
        visited[m] = true;
        vector<int> adj;
        for (int i = 0; i < n; ++i)
        {
            int x = isConnected[m][i];
            if (x == 1)
                adj.push_back(i);
        }
        for (auto x:adj)
        {
            if (!visited[x])
            {
                DFS(x,n,isConnected,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n=isConnected.size();
        vector<bool> visited(n,0);
        int rez=0;
        for (int i=0;i<n;++i)
        {
            if (!visited[i])
            {
                ++rez;
                DFS(i,n,isConnected,visited);
            }
        }
        return rez;
    }
};

int main()
{
    vector<vector<int>> edges = {
        {1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}
    };
    Solution a;
    int res = a.findCircleNum(edges);
    return 0;
}
