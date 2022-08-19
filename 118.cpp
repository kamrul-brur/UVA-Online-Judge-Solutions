/*
118 - Mutant Flatworld Explorers
*/
#include<bits/stdc++.h>
using namespace std;

char directions[]= {'N','E','S','W'};
int dx[]= {0, 1, 0, -1};
int dy[]= {1, 0, -1, 0};

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int xrange,yrange,x,y;
    cin>>xrange>>yrange;
    vector<vector<bool>>scent(xrange+1,vector<bool>(yrange+1,false));
    char initialDirection;
    string orders;
    while(cin>>x>>y>>initialDirection>>orders)
    {

        int direction_mode ;
        for(int i=0; i<4; i++)
        {
            if(directions[i]==initialDirection)
            {
                direction_mode=i;
            }
        }
        bool died=false;
        for(int i=0; i<orders.size(); i++)
        {
            if(orders[i]=='R')
            {
                direction_mode=(direction_mode+1)%4;
            }
            else if(orders[i]=='L')
            {
                direction_mode=(direction_mode+3)%4;
            }
            else
            {
                int px = x+dx[direction_mode];
                int py = y+dy[direction_mode];
                if(px<0||px>xrange ||py<0||py>yrange)
                {
                    if(!scent[x][y])
                    {
                        scent[x][y]=true;
                        died=true;
                        break;
                    }
                }
                else
                {
                    x=px;
                    y=py;
                }
            }
        }
        cout<<x<<" "<<y<<" "<<directions[direction_mode]<<(died ? " LOST" : "")<<endl;
    }
    return 0;
}

/*
Sample Input
5 3
1 1 E
RFRFRFRF
3 2 N
FRRFLLFFRRFLL
0 3 W
LLFFFLFLFL

Sample Output
1 1 E
3 3 N LOST
2 3 S
*/
