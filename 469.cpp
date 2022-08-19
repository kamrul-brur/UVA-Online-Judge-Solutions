/*
469 - Wetlands of Florida
*/

#include<bits/stdc++.h>
using namespace std;

char mat[105][105];
bool vis[105][105];
int dx[]= {-1,-1,-1,+0,+1,+1,+1,+0};
int dy[]= {-1,+0,+1,+1,+1,+0,-1,-1};
int cnt,row,col;

void dfs(int a,int b)
{
    if(a<0 || a==row || b<0 || b==col || mat[a][b]=='L' || vis[a][b])
        return;
    vis[a][b]=true;
    cnt++;
    for(int i=0; i<8; i++)
    {
        int x = a+dx[i];
        int y = b+dy[i];
        dfs(x,y);
    }
}

int main()
{
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    int t;
    scanf("%d",&t);
    getchar();
    getchar();
    bool firstLine =false;
    while(t--)
    {
        row=0,col=0;
        char temp[1000];
        if(firstLine)
            printf("\n");
        firstLine=true;
        while(gets(temp) && strlen(temp)>0)
        {
            if(temp[0]=='W' || temp[0]=='L')
            {
                strcpy(mat[row],temp);
                col = strlen(temp);
                row++;
            }
            else
            {
                int a,b;
                sscanf(temp,"%d %d",&a,&b);
                memset(vis,false,sizeof(vis));
                cnt=0;
                dfs(a-1,b-1);
                printf("%d\n",cnt);
            }
        }
    }
    return 0;
}

/*
Sample Input
1
LLLLLLLLL
LLWWLLWLL
LWWLLLLLL
LWWWLWWLL
LLLWWWLLL
LLLLLLLLL
LLLWWLLWL
LLWLWLLLL
LLLLLLLLL
3 2
7 5

Sample Output
12
4
*/


