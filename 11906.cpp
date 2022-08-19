/*
11906 - Knight in a War Grid
*/

#include<bits/stdc++.h>
using namespace std;
int r,c,m,n,w;
int mat[101][101];
int main()
{
    //freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int t,tc=0;
    cin>>t;
    while(t--)
    {
        memset(mat,0,sizeof(mat));

        cin>>r>>c>>m>>n;
        cin>>w;
        map<pair<int,int>,bool>waterMap;
        ///marking watermap grid
        for(int i=0; i<w; i++)
        {
            int a,b;
            cin>>a>>b;
            waterMap[ {a,b}]=true;
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        map<pair<int,int>,bool>vis;
        vis[ {0,0}]=true;
        int dx[] = {+m,+m,-m,-m,+n,+n,-n,-n};
        int dy[] = {+n,-n,+n,-n,+m,-m,+m,-m};
        while(!q.empty())
        {
            pair<int,int> pop = q.front();
            q.pop();
            set<pair<int,int>>distinct;
            for(int i=0; i<8; i++)
            {
                int x = dx[i]+pop.first;
                int y = dy[i]+pop.second;
                distinct.insert({x,y});
            }
            for(auto it : distinct)
            {
              //  pair<int,int> pp = *it;
                int newX = it.first;
                int newY = it.second;
                if(newX>=0 && newX<r && newY>=0 && newY<c && !waterMap[ {newX,newY}])
                {
                    mat[newX][newY]++;
                    if(!vis[ {newX,newY}])
                    {
                        vis[{newX,newY}]=true;
                        q.push({newX,newY});
                    }
                }
            }
        }
        int odd=0,even=0;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(mat[i][j] || (i==0 && j==0))
                {
                    if(mat[i][j]%2==1)
                        odd++;
                    else
                        even++;
                }
            }
        }
        cout<<"Case "<<(++tc)<<": "<<even<<" "<<odd<<endl;
    }
    return 0;
}
/*
Sample Input
2
3 3 2 1
0
4 4 1 2
2
3 3
1 1

Sample Output
Case 1: 8 0
Case 2: 4 10
*/
