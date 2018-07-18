#include<bits/stdc++.h>

using namespace std;

vector < vector<int> > adj;
vector < vector<int> > revAdj;
vector <int> visited;
int nodes, edges;

stack <int> listbyFinishTime;

void createGraph(int egdes)
{
    int a, b;
    for(int i=0; i<edges; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        revAdj[b].push_back(a);
    }
}

void dfs(int startingNode)
{
    visited[startingNode] = true;
        for(int i = 0; i < adj[startingNode].size(); i++)
        {
            if(visited[adj[startingNode][i]] == false)
            {
                dfs(adj[startingNode][i]);
            }
        }
        listbyFinishTime.push(startingNode);

}

void dfsRev(int startingNode)
{
        visited[startingNode] = true;
        cout << startingNode << " ";
        for(int i = 0; i < revAdj[startingNode].size(); i++)
        {
            if(visited[revAdj[startingNode][i]] == false)
            {
                dfsRev(revAdj[startingNode][i]);
            }
        }
}

int main()
{
    cout << "Input nodes and edges = ";
    cin >> nodes >> edges;

    adj.assign(nodes, vector<int>());
    revAdj.assign(nodes, vector<int>());

    visited.assign(nodes, false);

    cout << "Creating Graph, input adjacents of edges: \n";
    createGraph(edges);

    for(int i = 0; i < nodes; i++)
    {
        if(visited[i] == false)
        {
            dfs(i);
        }

    }

    visited.assign(nodes, false);
    while(listbyFinishTime.empty() == false)
    {
        int temp = listbyFinishTime.top();
        listbyFinishTime.pop();
        if(visited[temp] == false)
        {
            dfsRev(temp);
            cout << endl;
        }
    }
    return 0;
}
