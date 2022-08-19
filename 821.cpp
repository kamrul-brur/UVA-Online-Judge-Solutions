/*
821 - Page Hopping
*/


/// Algorithm : Floyd-Warshall

#include<bits/stdc++.h>
using namespace std;
int graph[101][101];
int a,b,N;
int main()
{
    int tc=0;
    while(scanf("%d %d",&a,&b)==2)
    {
        if(a==0 && b==0)
            break;
        for(int i=0; i<100; i++)
        {
            for(int j=0; j<100; j++)
            {
                if(i==j)
                    graph[i][j]=0;
                else
                    graph[i][j]=10000;
            }
        }
        N=0;
        while(1)
        {
            N = max(max(N,a),b);
            graph[a-1][b-1]=1;
            scanf("%d %d",&a,&b);
            if(a==0 && b==0)
                break;
        }
        ///now find the shortest path for every pair here
        for(int k=0; k<N; k++)
        {
            for(int i=0; i<N; i++)
            {
                for(int j=0; j<N; j++)
                {
                    graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
                }
            }
        }
        int cnt=0;
        int sum=0;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(i!=j && graph[i][j]!=10000)
                {
                    sum+=graph[i][j];
                    cnt++;
                }
            }
        }
        printf("Case %d: average length between pages = %.3f clicks\n",++tc,(float)sum/cnt);
    }
return 0;
}
/*
Sample Input
1 2 2 4 1 3 3 1 4 3 0 0
1 2 1 4 4 2 2 7 7 1 0 0
0 0

Sample Output
Case 1: average length between pages = 1.833 clicks
Case 2: average length between pages = 1.750 clicks
*/
