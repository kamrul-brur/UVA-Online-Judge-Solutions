/*
117 - The Postal Worker Rings Once
*/
#include<bits/stdc++.h>
using namespace std;
const int maxx = 1000;
const int INF = 30000;

int graph[30][30];
int degree[30];
void initialize()
{
    for(int i=0; i<30; i++)
    {
        for(int j=0; j<30; j++)
            graph[i][j]=INF;
        graph[i][i]=0;
    }
}
void floyd_warshall()
{
    for(int k=0; k<27; k++)
    {
        for(int i=0; i<27; i++)
        {
            for(int j=0; j<27; j++)
            {
                if(graph[i][j]>graph[i][k]+graph[k][j])
                {
                    graph[i][j] = graph[i][k]+graph[k][j];
                }
            }
        }
    }
}

void calculation(int sum)
{
    int od1=-1,od2=-1;
    for(int i=0; i<28; i++)
    {
        if(degree[i]%2==1)
        {
            od1 = i;
            break;
        }
    }
    for(int i=28; i>=0; i--)
    {
        if(degree[i]%2==1)
        {
            od2 = i;
            break;
        }
    }
    if(od1<0 && od2<0)
    {
        printf("%d\n",sum);
        return;
    }
    floyd_warshall();
    printf("%d\n",graph[od1][od2]+sum);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u,v,len,sum=0;
    char str[maxx];
    while(scanf("%s",&str)==1)
    {
        initialize();
        u = str[0]-'a';
        len = strlen(str);
        v = str[len-1]-'a';
        sum+=len;
        graph[u][v]=graph[v][u]=len;
        degree[u]++;
        degree[v]++;
        while(1)
        {
            scanf("%s",&str);
            if(!strcmp(str,"deadend"))
                break;
            u = str[0]-'a';
            len = strlen(str);
            v = str[len-1]-'a';
            sum+=len;
            graph[u][v]=graph[v][u]=len;
            degree[u]++;
            degree[v]++;
        }
        calculation(sum);
        for(int i=0; i<30; i++)
        {
            degree[i]=0;
        }
        sum=0;
    }
    return 0;
}

/*
Sample Input
one
two
three
deadend
mit
dartmouth
linkoping
tasmania
york
emory
cornell
duke
kaunas
hildesheim
concord
arkansas
williams
glasgow
deadend

Sample Output
11
114

*/
