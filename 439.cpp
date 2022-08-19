/*
439 - Knight Moves
*/
#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
int fx[]= {-2,-1,1,2,2,1,-1,-2};
int fy[]= {-1,-2,-2,-1,1,2,2,1};

int dis[100][100],vis[100][100];

int row=8,col=8;

void bfs(int sx,int sy)
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            vis[i][j]=0;
            dis[i][j]=0;
        }
    }
    vis[sx][sy]=1;
    dis[sx][sy]=0;
    queue<pii>q;
    q.push(pii(sx,sy));
    while(!q.empty())
    {
        pii top = q.front();
        q.pop();
        for(int k=0; k<8; k++)
        {
            int tx = top.first+fx[k];
            int ty = top.second+fy[k];
            if(tx>=0 && tx<row && ty>=0 && ty<col && vis[tx][ty]==0)
            {
                vis[tx][ty]=1;
                dis[tx][ty] = dis[top.first][top.second]+1;
                q.push(pii(tx,ty));
            }
        }
    }

}

int main()
{
    string one,two;
    while(cin>>one)
    {
        cin>>two;
        int s1,s2;
        int z1,z2;
        s1 = one[0]-97;
        s2 = one[1]-'0'-1;

        z1 = two[0]-97;
        z2 = two[1]-'0'-1;
        bfs(s1,s2);

        cout<<"To get from "<<one<<" to "<<two<<" takes "<<dis[z1][z2]<<" knight moves."<<endl;
        one.clear();
        two.clear();
    }
    return 0;
}

/*
Sample Input
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6

Sample Output
To get from e2 to e4 takes 2 knight moves.
To get from a1 to b2 takes 4 knight moves.
To get from b2 to c3 takes 2 knight moves.
To get from a1 to h8 takes 6 knight moves.
To get from a1 to h7 takes 5 knight moves.
To get from h8 to a1 takes 6 knight moves.
To get from b1 to c3 takes 1 knight moves.
To get from f6 to f6 takes 0 knight moves.
*/
