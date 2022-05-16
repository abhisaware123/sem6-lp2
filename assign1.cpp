#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int N;
    vector<vector<int>> vect;

public:
    Graph(int n)
    {
        N = n;
        vect = vector<vector<int>>(N);
    };

    void addedge(int s, int e)
    {
        vect[s].push_back(e);
        vect[e].push_back(s);
    }

    void bfs(int start)
    {
        queue<int> q;
        q.push(start);
        vector<bool> visited(N + 1, false);
        visited[start] = true;

        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            cout << x << " ->  ";

            for (auto edg : vect[x])
            {
                if (!visited[edg])
                {
                    visited[edg] = true;
                    q.push(edg);
                }
            }
        }
    }

    void dfs(int start, vector<bool> &visited)
    {
        if (visited[start] == true)
        {
            return;
        }
        cout << start << " ->  ";
        visited[start] = true;
        for (auto adjnode: vect[start])
        {
            if (!visited[adjnode])
            {
                dfs(adjnode, visited);
            }
        }
    }
};

int main()
{
    int N, noofedges, s, e;

    cout << "Enter number of nodes : ";
    cin >> N;

    Graph g(N);

    cout << "enter number of edges : ";
    cin >> noofedges;

    for (int i = 0; i < noofedges; i++)
    {
        int start;
        int end;
        cin >> start >> end;
        g.addedge(start, end);
    }

   
    cout << "Enter start node : ";
    int n;
    cin >> n;

    cout <<"\n BFS traversal : ";
    g.bfs(n);

    vector<bool> visited( N,false);
    cout << "\n\n DFS traversal :" ;
    g.dfs(0, visited);

    return 0;
}