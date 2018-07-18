#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{
    map <T, vector<pair<T, int> > > m;
    map <T, T> par;
    map <T, int> dist;

public:
    void addEdge(T u, T v, int dist)
    {
        m[u].push_back(make_pair(v, dist));
        m[v].push_back(make_pair(u, dist));

        par[u] = u;
    }

    void dijkstraSPD(T startingNode)
    {

        for(auto j:m)
        {
            dist[j.first] = INT_MAX;
        }

        set <pair<int, T> > s;
        dist[startingNode] = 0;
        s.insert(make_pair(0, startingNode));

        while(!s.empty())
        {
            auto i = *(s.begin());

            T node = i.second;
            int nodeDist = i.first;

            s.erase(s.begin());

            for(auto adj:m[node])
            {
                T dest = adj.first;
                int edgeDist = adj.second;

                if(nodeDist + edgeDist < dist[dest])
                {
                    auto f = s.find(make_pair(dist[dest], dest));
                    if(f!=s.end())
                    {
                        s.erase(f);
                    }
                    dist[dest] = nodeDist + edgeDist;
                    s.insert(make_pair(dist[dest], dest));

                    par[dest] = node;
                }
            }
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
        p = par[p];
        if(p == par[p])
        {
            s.push(p);
            return;
        }
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

    int nodes, edges;
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

    Bangladesh.dijkstraSPD(startingNode);
    //Bangladesh.printPath(destinationNode);
    Bangladesh.printallPaths();

    return 0;
}
