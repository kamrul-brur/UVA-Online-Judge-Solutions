/*
11953 - Battleships
*/

#include<bits/stdc++.h>
using namespace std;
int row,col,cnt;
char v[105][105];
int dx[]= {-1,+0,+1,+0};
int dy[]= {+0,+1,+0,-1};

void dfs(int a,int b)
{
    if(a<0 || a==row || b<0 || b==col)
        return;
    if(v[a][b]=='.')
        return;
    v[a][b]='.';
    for(int i=0; i<4; i++)
    {
        int x = a+dx[i];
        int y = b+dy[i];
        dfs(x,y);
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    int tc,t=1;
    cin>>tc;
    while(tc--)
    {
        cin>>row;
        col=row;
        for(int i=0; i<row; i++)
        {
            cin>>v[i];
        }
        int ans = 0;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                cnt=0;
                if(v[i][j]=='x')
                {
                    ans++;
                    dfs(i,j);
                }

            }
        }
        cout<<"Case "<<(t++)<<": "<<ans<<endl;
    }
    return 0;
}
/*
Sample Input
2
4
x...
..x.
@.@.
....
2
..
x.

Sample Output
Case 1: 2
Case 2: 1
*/
