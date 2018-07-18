#include<bits/stdc++.h>

using namespace std;

vector < vector<int> > adj;
vector <int> visited;
int nodes, edges;
int startingNode;

queue <int> q;
stack <int> TopoList;

void createGraph(int egdes)
{
    int a, b;
    for(int i=0; i<edges; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        //adj[b].push_back(a);
    }
}

void dfs(int startingNode)
{
    visited[startingNode] = true;
    //cout << startingNode << " ";
    for(int i = 0; i < adj[startingNode].size(); i++)
    {
        if(visited[adj[startingNode][i]] == false)
        {
            dfs(adj[startingNode][i]);
        }
    }
    TopoList.push(startingNode);
}

int main()
{
    cout << "Input nodes and edges = ";
    cin >> nodes >> edges;

    adj.assign(nodes, vector<int>());
    visited.assign(nodes, false);

    cout << "Creating Graph, input adjacents of edges: \n";
    createGraph(edges);

    for(int i = 0; i < nodes; i++)
    {
        if(!visited[startingNode])
        {
            dfs(i);
        }

    }

    cout << "TopoList order: \n";
    for(int i=0; i < nodes; i++)
    {
        int temp;
        temp = TopoList.top();
        cout << temp << " ";
        TopoList.pop();
    }

    return 0;
}
