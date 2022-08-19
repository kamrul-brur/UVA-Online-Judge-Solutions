/*
820 - Internet Bandwidth
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int src,dest,line,n,tc=1;
    while(cin>>n && n!=0)
    {
        vector<vector<int>>graph(n+1,vector<int>(n+1,0));
        cin>>src>>dest>>line;
        for(int i=1; i<=line; i++)
        {
            int x,y,c;
            cin>>x>>y>>c;
            graph[x][y]+=c;
            graph[y][x]+=c;
        }
        int max_flow=0,u,v;
        ///bfs until there is a path from source to destination
        while(true)
        {
            vector<int>parent(n+1,-1);
            queue<int>q;
            parent[src]=src;
            q.push(src);
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                for(int v=1; v<=n; v++)
                {
                    if(graph[u][v]>0 && parent[v]==(-1))
                    {
                        parent[v]=u;
                        q.push(v);
                    }
                }
            }

            ///this means destination is not visited yet
            if(parent[dest]==-1)
                break;
            int temp=INT_MAX;
            int curr=dest;
            while(curr!=src)
            {
                int prev = parent[curr];
                temp=min(temp,graph[prev][curr]);
                curr=prev;
            }
            curr=dest;
            while(curr!=src)
            {
                int prev = parent[curr];
                graph[prev][curr]-=temp;
                graph[curr][prev]+=temp;
                curr=prev;
            }
            ///find the minimum value across the path
            /// max_flow+=minimum_value(graph,parent,MAX_BANDWIDTH,dest,src);
            max_flow+=temp;
        }
        cout<<"Network "<<(tc++)<<endl;
        cout<<"The bandwidth is "<<max_flow<<"."<<endl;
        cout<<endl;
    }
    return 0;
}

/*
Sample Input
4
1 4 5
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20
0

Sample Output

Network 1
The bandwidth is 25.
*/
