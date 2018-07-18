#include<bits/stdc++.h>

using namespace std;

vector < vector<int> > adj;
vector <int> visited;
int nodes, edges;
int startingNode;

queue <int> q;

void createGraph(int egdes)
{
    int a, b;
    for(int i=0; i<edges; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

void dfs(int startingNode)
{
    visited[startingNode] = true;
    cout << startingNode << " ";
    for(int i = 0; i < adj[startingNode].size(); i++)
    {
        if(visited[adj[startingNode][i]] == false)
        {
            dfs(adj[startingNode][i]);
        }
    }
}

int main()
{
    cout << "Input nodes and edges = ";
    cin >> nodes >> edges;

    adj.assign(nodes, vector<int>());
    visited.assign(nodes, false);

    cout << "Creating Graph, input adjacents of edges: \n";
    createGraph(edges);

    printf("The path of visiting is: ");
    cin >> startingNode;

    dfs(startingNode);

    return 0;
}
