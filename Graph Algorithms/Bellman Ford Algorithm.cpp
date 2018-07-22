#include <bits/stdc++.h>
using namespace std;

int nodes, edges;
bool printable = true;

template <typename T>
class Graph
{
    map <T, vector<pair<T, int> > > m;
    map <T, T> par;
    map <T, int> dist;

public:
    void addEdge(T u, T v, int dist)
    {
        m[u].push_back(make_pair(v, dist));
        par[u] = u;
        par[v] = u;
    }

    void bellmanFordSPD(T startingNode)
    {
        bool noSol = false;

        for(auto j:par)
        {
            dist[j.first] = INT_MAX;
        }

        dist[startingNode] = 0;
        for(int i = 1; i < nodes; i++)
        {
            for(auto j:m)
            {
                T node = j.first;
                vector<pair<T, int> > k = j.second;
                T dest = k[0].first;
                int edgeDist = k[0].second;
                int nodeDist = dist[node];
                if(nodeDist + edgeDist < dist[dest])
                {
                    dist[dest] = nodeDist + edgeDist;
                    par[dest] = node;
                }
            }
        }
        for(auto j:m)
        {
            T node = j.first;
            vector<pair<T, int> > k = j.second;
            T dest = k[0].first;
            int edgeDist = k[0].second;
            int nodeDist = dist[node];
            if(nodeDist + edgeDist < dist[dest])
            {
                noSol = true;
            }
        }

        if(noSol)
        {
            cout << "\nDEADLOCK! NEGATIVE CYCLE IN GRAPH!!!" << endl;
            printable = false;
        }
    }
    stack <T> s;
    void printPath(T destinationNode)
    {
        cout << destinationNode << " ";
        cout << dist[destinationNode] << " ";
        findPar(destinationNode);
        //cout << "Fesible path is: ";
        while(!s.empty())
        {
            //string t = (s.size() == 1) ? "" : "->";
            cout << s.top() << " "; // << t;
            s.pop();
        }
    }

    void findPar(T p)
    {
        s.push(p);

        if(p == par[p])
        {
            //s.push(p);
            return;
        }
        p = par[p];
        findPar(p);
    }

    void printallPaths()
    {
        for(auto j:dist)
        {
            printPath(j.first);
            cout<< endl;
        }
    }
};

int main()
{
    Graph<string> Bangladesh;
    cin >> nodes >> edges;
    for(int i=0; i< edges; i++)
    {
        string src, des;
        int cost;
        cout << "Source, Destination and Cost: ";
        cin >> src >> des >> cost;
        Bangladesh.addEdge(src, des, cost);
    }

    string startingNode, destinationNode;
    cout << "Source? : ";
    cin >> startingNode;
    //cout << "Destination? : ";
    //cin >> destinationNode;

    Bangladesh.bellmanFordSPD(startingNode);
    //Bangladesh.printPath(destinationNode);
    if(printable)
        Bangladesh.printallPaths();

    return 0;
}
