/*
11463 - Commandos
*/

#include<bits/stdc++.h>
using namespace std;

const int INF = (1e7);

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int t,n,r,tc=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>r;
        int graph[n+1][n+1];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                graph[i][j]=INF;
            }
        }
        for(int i=0; i<r; i++)
        {
            int x,y;
            cin>>x>>y;
            graph[x][y]=1;
            graph[y][x]=1;
        }
        for(int i=0; i<n; i++)
        {
            graph[i][i]=0;
        }
        ///floyd warshall
        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
                }
            }
        }
        int s,e,ans=0;
        cin>>s>>e;
        for(int i=0; i<n; i++)
        {
            if(graph[s][i]!=INF && graph[i][e]!=INF)
            {
                ans = max(ans,graph[s][i]+graph[i][e]);
            }
        }
        cout<<"Case "<<(++tc)<<": "<<ans<<endl;
    }
    return 0;
}
/*
Sample Input
2
4
3
0 1
2 1
1 3
0 3
2
1
0 1
1 0

Sample Output
Case 1: 4
Case 2: 1
*/
