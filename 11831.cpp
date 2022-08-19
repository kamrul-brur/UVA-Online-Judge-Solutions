/*
11831 - Sticker Collector Robot
*/

#include<bits/stdc++.h>
using namespace std;
int n,m,len,orientation,x,y;
char graph[101][101],rules[50005];

int traverse()
{
    int cnt=0,u,v;
    for(int k=0; k<len; k++)
    {
        ///turn right
        if(rules[k]=='D')
        {
            orientation = (orientation+1)%4;
        }
        else if(rules[k]=='E')
        {
            ///turn left
            orientation=orientation-1;
            if(orientation<0)
                orientation=3;
        }
        else
        {
            ///for F it will go forward
            u=x,v=y;
            if(orientation==0)
                u--;
            else if(orientation==1)
                v++;
            else if(orientation==2)
                u++;
            else
                v--;
            if(u<1 || u>n || v<0 || v>=m || graph[u][v]=='#')
                continue;
            else
            {
                graph[x][y]='.';
                if(graph[u][v]=='*')
                    cnt++;
                x=u,y=v;
            }
        }
    }
    return cnt;
}
int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n>>m>>len)
    {
        if(n==0 && m==0 && len==0)
            break;
        for(int i=1; i<=n; i++)
        {
            cin>>graph[i];
        }
        cin>>rules;
        bool found =false;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(graph[i][j]=='N' ||graph[i][j]=='S'||graph[i][j]=='L'||graph[i][j]=='O')
                {
                    x=i,y=j;
                    found =true;
                    break;
                }
            }
            if(found)
                break;
        }
        if(graph[x][y]=='N')
            orientation=0;
        else if(graph[x][y]=='L')
            orientation=1;
        else if(graph[x][y]=='S')
            orientation=2;
        else if(graph[x][y]=='O')
            orientation=3;
        cout<<traverse()<<endl;
    }
    return 0;
}

/*
Sample Input
3 3 2
***
*N*
***
DE
4 4 5
...#
*#O.
*.*.
*.#.
FFEFF
10 10 20
....*.....
.......*..
.....*....
..*.#.....
...#N.*..*
...*......
..........
..........
..........
..........
FDFFFFFFEEFFFFFFEFDF
0 0 0

Sample Output
0
1
3
*/

