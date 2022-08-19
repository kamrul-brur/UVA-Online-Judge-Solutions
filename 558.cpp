/*
558 - Wormholes
*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node
{
    int u,v,cost;
};
vector<node>graph(2010);
vector<int>dist(1005);
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0; i<=n; i++)
        {
            dist[i]=INT_MAX;
        }
        graph.clear();
        for(int i=0; i<m; i++)
        {
            node temp;
            cin>>temp.u>>temp.v>>temp.cost;
            graph.push_back(temp);
        }
        dist[0]=0;
        for(int i=0; i<n-1; i++)
        {
            for(int j=0; j<m; j++)
            {
                int u = graph[j].u;
                int v = graph[j].v;
                int c = graph[j].cost;
                if(dist[u]+c<dist[v])
                {
                    dist[v]=dist[u]+c;
                }
            }
        }

        bool found = false;
        for(int j=0; j<m; j++)
        {
            int u = graph[j].u;
            int v = graph[j].v;
            int c = graph[j].cost;
            if(dist[u]+c<dist[v])
            {
                found=true;
            }
        }
        if(found)
        {
            cout<<"possible"<<endl;
        }
        else
        {
            cout<<"not possible"<<endl;
        }

    }
    return 0;
}

/*
Sample Input
2
3 3
0 1 1000
1 2 15
2 1 -42
4 4
0 1 10
1 2 20
2 3 30
3 0 -60

Sample Output
possible
not possible
*/
