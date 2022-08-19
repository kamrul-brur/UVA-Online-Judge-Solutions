/*
259 - Software Allocation
*/
#include<bits/stdc++.h>
using namespace std;
const int INF = (1e5);
const int LIM = 38;
char A,B;
char input1[100],input2[20];
int graph[38][38],total;

void print_answer(int rgraph[LIM][LIM],int i)
{
    for(int j=1; j<27; j++)
    {
        if(rgraph[i][j]==1)
        {
            printf("%c",'A'+j-1);
            return;
        }
    }
    printf("_");
    return;
}

bool bfs(int rgraph[LIM][LIM],int s,int t,int parent[])
{
    bool visit[LIM]= {false};
    queue<int>q;
    q.push(s);
    parent[s]=-1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v=0; v<LIM; v++)
        {
            if(visit[v]==false && rgraph[u][v]>0)
            {
                if(v==t)
                {
                    parent[v]=u;
                    return true;
                }
                q.push(v);
                visit[v]=true;
                parent[v]=u;
            }
        }
    }
    return false;
}


void ford_fulkerson(int graph[LIM][LIM],int s,int t,int total)
{
    int u,v;
    int rgraph[LIM][LIM];
    for(int i=0; i<LIM; i++)
    {
        for(int j=0; j<LIM; j++)
        {
            rgraph[i][j]=graph[i][j];
        }
    }
    int parent[LIM];
    int max_flow=0;
    while(bfs(rgraph,s,t,parent))
    {
        int path_flow=INT_MAX;
        for(v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow=min(path_flow,rgraph[u][v]);
        }
        for(v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            rgraph[u][v]-=path_flow;
            rgraph[v][u]+=path_flow;
        }
        max_flow+=path_flow;
    }
    if(max_flow==total)
    {
        for(int i=27; i<37; i++)
        {
            print_answer(rgraph,i);
        }
    }
    else
    {
        cout<<"!";
    }
    printf("\n");
    return;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(1)
    {
        if(gets(input1)==0)
            break;
        total=0;
        memset(graph,0,sizeof(graph));
        do
        {
            if(strcmp(input1,"")==0)
                break;
            ///copying input into 3 parts
            sscanf(input1,"%c%c %s",&A,&B,input2);
            graph[0][A-'A'+1]=(B-'0');
            total+=(B-'0');
            for(int i=0;; i++)
            {
                if(input2[i]==';')
                    break;
                graph[A-'A'+1][27+input2[i]-'0']=INF;
            }
        }
        while(gets(input1));
        for(int i=27; i<37; i++)
        {
            graph[i][37]=1;
        }
        ///graph is ready .. now maximum flow algorithm
        ford_fulkerson(graph,0,37,total);

    }
    return 0;
}

/*
Sample Input
A4 01234;
Q1 5;
P4 56789;
A4 01234;
Q1 5;
P5 56789;

Sample Output
AAAA_QPPPP
!
*/
