/*
352 - The Seasonal War
*/
#include<bits/stdc++.h>
using namespace std;
int n,row,col;
vector<string>v;
int vis[1005][1005];

int dx[]= {-1,-1,-1,+0,+1,+1,+1,+0};
int dy[]= {-1,+0,+1,+1,+1,+0,-1,-1};

void dfs(int a,int b)
{
    if(a<0 || a==row || b<0 || b==col || v[a][b]=='0' || vis[a][b])
        return;
    vis[a][b]=true;
    for(int i=0; i<8; i++)
    {
        int x = a+dx[i];
        int y = b+dy[i];
        dfs(x,y);
    }
}

int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int tc=0;
    while(cin>>n)
    {
        v.clear();
        string str;
        for(int i=0; i<n; i++)
        {
            cin>>str;
            v.push_back(str);
        }
        row = v.size();
        col = v[0].size();
        memset(vis,false,sizeof(vis));
        int cnt=0;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(v[i][j]=='1' && vis[i][j]==false)
                {
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        cout<<"Image number "<<(++tc)<<" contains "<<cnt<<" war eagles."<<endl;
    }
    return 0;
}
/*
Sample input
6
100100
001010
000000
110000
111000
010100
8
01100101
01000001
00011000
00000010
11000011
10100010
10000001
01100000

Sample output
Image number 1 contains 3 war eagles.
Image number 2 contains 6 war eagles.
*/
