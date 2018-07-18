#include <bits/stdc++.h>
using namespace std ;

int par[100];

int findPar(int i)
{
    if (par[i] == i)
    {
        return i;
    }
    else
        findPar(par[i]);
}
void unionSet(int a , int b)
{
    int root_a= findPar(a);
    int root_b= findPar(b);
    par[root_a]= par[root_b];
}
int krushkal(pair<int, pair<int , int> > adj[], int edges)
{
    int x, y, cost, mincost=0;
    for (int i=1; i<= edges; i++)
    {
        x= adj[i].second.first;
        y= adj[i].second.second;
        cost= adj[i].first;

        //if the vertexes don't create loop
        if(findPar(x)!= findPar(y))
        {
            cout << x << "---" << y << " " << cost << endl;
            mincost+= cost;
            unionSet(x,y);
        }
    }
    return mincost;
}
int main()
{

        int nodes, edges;
        cin >> nodes >> edges;

        //adj[] = pair <weight, adjOfNodes>
        pair <int , pair<int , int > > adj[edges];

        //taking weighted graph input
        for (int i=1; i<= edges ; i++)
        {
            int x, y, w;
            cin >> x >> y >> w;
            adj[i]= make_pair(w, make_pair(x,y));

        }

        //making each of the nodes parent the nodes itself
        for (int i=1; i<= nodes; i++)
        {
            par[i]=i;
        }

        //sorting using first value (here weight) of pair
        sort(adj, adj+edges);

        int mincost= krushkal(adj, edges);
        cout<<mincost<<endl;

        return 0;
}
