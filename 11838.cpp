/*
11838 - Come and Go
*/

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>g1(2000),g2(2000);
vector<bool>visited(2000);
vector<int>order,element;
int n,m;
void dfs1(int v)
{
    visited[v]=true;
    for(int i=0; i<g1[v].size(); i++)
    {
        if(!visited[g1[v][i]])
        {
            dfs1(g1[v][i]);
        }
    }
    order.push_back(v);
}
void dfs2(int v)
{
    visited[v]=true;
    element.push_back(v);
    for(int i=0; i<g2[v].size(); i++)
    {
        if(!visited[g2[v][i]])
        {
            dfs2(g2[v][i]);
        }
    }
}
void initialize()
{
    for(int i=0; i<=n; i++)
    {
        g1[i].clear();
        g2[i].clear();
    }
    order.clear();
    element.clear();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c;
    while(scanf("%d %d",&n,&m)==2)
    {
        if(n==0 && m==0)
        {
            break;
        }
        initialize();
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(c==1)
            {
                g1[a].push_back(b);
                g2[b].push_back(a);
            }
            else if(c==2)
            {
                g1[a].push_back(b);
                g1[b].push_back(a);
                g2[a].push_back(b);
                g2[b].push_back(a);
            }
        }
        for(int i=0; i<=n; i++)
        {
            visited[i]=false;
        }
        for(int i=1; i<=n; i++)
        {
            if(!visited[i])
            {
                dfs1(i);
            }
        }
        for(int i=0; i<=n; i++)
        {
            visited[i]=false;
        }
        bool flag =false;

        int v = order[n-1];
        if(!visited[v])
        {
            dfs2(v);
            if(element.size()==n)
            {
                flag=true;
            }
            element.clear();
        }
        if(flag)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
/*
Sample Input
4 5
1 2 1
1 3 2
2 4 1
3 4 1
4 1 2
3 2
1 2 2
1 3 2
3 2
1 2 2
1 3 1
4 2
1 2 2
3 4 2
0 0

Sample Output
1
1
0
0
*/
