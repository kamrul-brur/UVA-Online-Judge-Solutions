/*
1112 - Mice and Maze
*/

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pp;

vector<pp>graph[101];
int cost[101];

void reset_all(int n)
{
    for(int i=0; i<=n; i++)
    {
        graph[i].clear();
        cost[i]=INT_MAX;
    }
}

void dijkstra(int e,int c,int t)
{
    priority_queue<pp,vector<pp>,greater<pp>>q;
    q.push(make_pair(c,e));
    cost[e]=c;
    while(!q.empty())
    {
        pp u = q.top();
        q.pop();
        int uu = u.second;
        ///this is u
        int tu = u.first;
        ///this is cost u
        if(cost[uu]>t)
            continue;
        for(int i=0; i<graph[uu].size(); i++)
        {
            pp v = graph[uu][i];
            ///this is v
            int tv = v.second;
            ///this is cost v
            int vv = v.first;
            if(tu+tv<cost[vv])
            {
                cost[vv]=tu+tv;
                q.push(make_pair(cost[vv],vv));
            }
        }
    }

}

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int t,tc=0;
    cin>>t;
    while(t--)
    {
        if(tc)printf("\n");
        tc=1;
        int m,n,e,t,x,y,c,ans=0;
        cin>>n>>e>>t;
        cin>>m;
        reset_all(n);
        for(int i=0; i<m; i++)
        {
            cin>>x>>y>>c;
            graph[y].push_back(make_pair(x,c));
        }
        dijkstra(e,0,t);
        for(int i=1; i<=n; i++)
        {
            if(cost[i]<=t)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

/*
Sample Input
1
4
2
1
8
1 2 1
1 3 1
2 1 1
2 4 1
3 1 1
3 4 1
4 2 1
4 3 1

Sample Output
3
*/
