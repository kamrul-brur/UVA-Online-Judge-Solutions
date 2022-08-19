/*
11902 - Dominator
*/

#include<bits/stdc++.h>
using namespace std;

int n;
bool mat[101][101];
bool vis[101];

void dfs(int node,int going)
{
    if(node==going)
        return;
    vis[node]=true;
    for(int i=0; i<n; i++)
    {
        if(mat[node][i] && !vis[i])
            dfs(i,going);
    }
}

void printLine()
{
    cout<<"+";
    for(int i=0; i<2*n-1; i++)
    {
        cout<<"-";
    }
    cout<<"+\n";
}

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        cin>>n;
        memset(mat,false,sizeof(mat));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>mat[i][j];
            }
        }
        bool output[101][101];
        bool firstvis[101];
        memset(vis,false,sizeof(vis));
        ///vis all nodes going from 0 node
        dfs(0,-1);
        for(int i=0; i<101; i++)
        {
            firstvis[i]=vis[i];
        }
        for(int i=0; i<n; i++)
        {
            memset(vis,false,sizeof(vis));
            dfs(0,i);
            for(int j=0; j<n; j++)
            {
                if(vis[j]!=firstvis[j])
                    output[i][j]=true;
                else
                    output[i][j]=false;
            }
            output[i][i]=firstvis[i];
        }
        cout<<"Case "<<tc<<":\n";
        printLine();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(output[i][j])
                {
                    cout<<"|Y";
                }
                else
                {
                    cout<<"|N";
                }
            }
            cout<<"|\n";
            printLine();
        }

    }
    return 0;
}

/*
Sample Input
2
5
0 1 1 0 0
0 0 0 1 0
0 0 0 1 0
0 0 0 0 1
0 0 0 0 0
1
1

Sample Output
Case 1:
+---------+
|Y|Y|Y|Y|Y|
+---------+
|N|Y|N|N|N|
+---------+
|N|N|Y|N|N|
+---------+
|N|N|N|Y|Y|
+---------+
|N|N|N|N|Y|
+---------+
Case 2:
+-+
|Y|
+-+
*/
