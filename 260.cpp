/*
260 - Il Gioco dell'X
*/
#include<bits/stdc++.h>
using namespace std;

int dx[]= {-1,-1,+0,+0,+1,+1};
int dy[]= {-1,+0,-1,+1,+0,+1};

char s[205][205];
int n;
bool vis[205][205];
bool ans;

void dfs(int x,int y)
{
    vis[x][y]=true;
    for(int i=0; i<6; i++)
    {
        int px = x+dx[i];
        int py = y+dy[i];
        if(!vis[px][py] && s[px][py]=='b' && px>=0 && px<n && py>=0 && py<n)
        {
            if(px==(n-1))
            {
                ans=true;
                return;
            }
            dfs(px,py);
        }
    }
}


int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int tc=0;
    while(cin>>n && n!=0)
    {
        memset(vis,false,sizeof(vis));
        for(int i=0; i<n; i++)
        {
            cin>>s[i];
        }
        ans=false;
        ///checking that black can reach into edge or not
        ///if reach then black wins otherwise white wins
        for(int i=0; i<n; i++)
        {
            dfs(0,i);
            if(ans==true)break;
        }
        if(ans)
        {
            cout<<(++tc)<<" B"<<endl;
        }
        else
        {
            cout<<(++tc)<<" W"<<endl;
        }
    }
    return 0;
}
/*
Sample Input
4
bbwb
wwbw
bbwb
bwww
4
bbwb
wwbw
bwwb
wwbb
0

Sample Output
1 W
2 B
*/
