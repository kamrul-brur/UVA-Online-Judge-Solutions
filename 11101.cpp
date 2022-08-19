/*
11101 - Mall Mania
*/

#include<bits/stdc++.h>
using namespace std;

int dx[]= {-1,+0,+1,+0};
int dy[]= {+0,+1,+0,-1};

int main()
{
    vector<vector<int>>grid(2001,vector<int>(2001));
    vector<vector<int>>movee(2001,vector<int>(2001));
    int n,m;
    while(cin>>n && n>0)
    {
        for(int i=0; i<2001; i++)
        {
            for(int j=0; j<2001; j++)
            {
                grid[i][j]=0;
                movee[i][j]=-1;
            }
        }
        queue<pair<int,int>>q;

        for(int i=0; i<n; i++)
        {
            int x,y;
            cin>>x>>y;
            grid[x][y]=1;
            movee[x][y]=0;
            q.push(make_pair(x,y));
        }
        cin>>m;
        for(int i=0; i<m; i++)
        {
            int x,y;
            cin>>x>>y;
            grid[x][y]=2;
        }
        int dist=0;
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            int tempx=p.first;
            int tempy=p.second;
            if(grid[tempx][tempy]==2)
            {
                dist=movee[tempx][tempy];
                break;
            }
            for(int i=0; i<4; i++)
            {
                int px = tempx+dx[i];
                int py = tempy+dy[i];
                if(px>=0 && px<=2000 && py>=0 && py<=2000 && movee[px][py]==-1)
                {
                    q.push(make_pair(px,py));
                    movee[px][py]=movee[tempx][tempy]+1;
                }
            }
        }
        cout<<dist<<endl;
    }
    return 0;
}
/*

*/
