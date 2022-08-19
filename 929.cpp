/*
929 - Number Maze
*/
#include<bits/stdc++.h>
using namespace std;
#define INF 1<<30
int dx[]= {-1,+0,+1,+0};
int dy[]= {+0,+1,+0,-1};
struct node
{
    int u,v;
    int cost;
    bool operator<(const node& p)const
    {
        return cost>p.cost;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>>graph(n,vector<int>(m));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>graph[i][j];
            }
        }
        priority_queue<node>q;
        node then;
        then.u=0;
        then.v=0;
        then.cost=graph[0][0];
        q.push(then);
        vector<vector<int>>cost(n,vector<int>(m,-1));
        cost[0][0]=then.cost;
        while(!q.empty())
        {
            node top = q.top();
            q.pop();
            int tempx=top.u;
            int tempy=top.v;
            int tempcost=top.cost;

            for(int i=0; i<4; i++)
            {
                int px = tempx+dx[i];
                int py = tempy+dy[i];
                if(px<0 || px>=n || py<0 || py>=m)
                    continue;
                if(cost[px][py]==-1 || cost[tempx][tempy]+graph[px][py]<cost[px][py])
                {
                    cost[px][py]=cost[tempx][tempy]+graph[px][py];
                    node inner;
                    inner.u=px;
                    inner.v=py;
                    inner.cost=cost[px][py];
                    q.push(inner);
                }
            }
        }
        cout<<cost[n-1][m-1]<<endl;
    }
    return 0;
}

/*
Sample Input
2
4
5
0 3 1 2 9
7 3 4 9 9
1 7 5 5 3
2 3 4 2 5
1
6
0 1 2 3 4 5

Sample Output
24
15
*/
