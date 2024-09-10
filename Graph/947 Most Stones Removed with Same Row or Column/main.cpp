#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;


class Solution
{
public:
    void DFS(vector<vector<int>>& graph, int v, vector<bool>& visited)
    {
        visited[v] = 1;
        for (auto u : graph[v])
        {
            if (!visited[u])
            {
                DFS(graph, u, visited);
            }
        }
    }

    int countVisited = 0;

    int removeStones(vector<vector<int>>& stones)
    {
        int n = stones.size();
        vector<vector<int>> graph(n);
        vector<bool> visited(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = i+1; j < n; ++j)
            {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                DFS(graph, i, visited);
                ++countVisited;
            }
        }
        return n-countVisited;
    }
};

class Sol
{
    vector<int> parent;
    int find(int x)
    {
        return parent[x]==x ? x : find (parent [x]);
    }
public:
    vector<int> findReduntConnection(vector<vector<int>>& edges)
    {
        int n=edges.size();

        parent.resize(n+1,0);
        for (int i=0;i<n;++i)
        {
            parent[i]=i;
        }

        vector<int> res(2,0);
        for (int i=0;i<n;++i)
        {
            int x=find(edges[i][0]);
            int y=find(edges[i][1]);
            if (x!=y)
            {
                parent[y]=x;
            }else
            {
                res[0]=edges[i][0];
                res[1]=edges[i][1];
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> stones = {{0,0}};
    Solution a;
    int res = a.removeStones(stones);
    return 0;
}
