#include<bits/stdc++.h>

using namespace std;

vector < vector<int> > adj;
vector <int> visited;
int nodes, edges;
int startingNode;

queue<int> q;

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

void bfs(int startingNode)
{
    q.push(startingNode);
    visited[startingNode] = true;
    printf("%d ", startingNode);
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        for(int i = 0; i < adj[f].size(); i++)
        {
            if(visited[adj[f][i]] == false)
            {
                visited[adj[f][i]] = true;
                cout << adj[f][i] << " ";
                q.push(adj[f][i]);
            }
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

    bfs(startingNode);

    return 0;
}
