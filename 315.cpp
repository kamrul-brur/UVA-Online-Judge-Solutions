/*
315 - Network
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>edge[100];
bool visit[105];
int n;

void dfs(int node)
{
    visit[node]=true;
    for(int i=0; i<edge[node].size(); i++)
    {
        if(!visit[edge[node][i]])
        {
            dfs(edge[node][i]);
        }
    }
}

int articulationPointAndBridge()
{
    for(int i=1; i<=n; i++)
    {
        if(!visit[i])
            return 1;
    }
    return 0;
}

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int x,y;
    char c;
    while(cin>>n)
    {
        memset(visit,false,sizeof(visit));
        if(n==0)
            break;
        while(scanf("%d",&x)==1 && x)
        {
            if(x==0)
                break;
            while(scanf("%d%c",&y,&c)==2)
            {
                edge[x].push_back(y);
                edge[y].push_back(x);
                if(c=='\n')
                    break;
            }
        }
        int cnt=0;
        for(int i=2; i<=n; i++)
        {
            memset(visit,false,sizeof(visit));
            visit[i]=true;
            dfs(1);
            cnt+=articulationPointAndBridge();
        }
        ///for root value
        memset(visit,0,sizeof(visit));
        visit[1]=true;
        dfs(2);
        cnt+=articulationPointAndBridge();
        cout<<cnt<<endl;
        for(int i=1; i<=n; i++)
        {
            edge[i].clear();
        }
    }
    return 0;
}
/*
Sample Input
5
5 1 2 3 4
0
6
2 1 3
5 4 6 2
0
0

Sample Output
1
2
*/
