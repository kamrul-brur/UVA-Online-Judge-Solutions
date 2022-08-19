/*
12160 - Unlock the Lock
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int l,r,u,tc=0;
    while(cin>>l>>u>>r &&!(l==0 && r==0 && u==0))
    {
        vector<int>cost(r);
        for(int i=0; i<r; i++)
        {
            cin>>cost[i];
        }
        vector<int>vis(10000,0);
        queue<int>q;
        q.push(l);
        while(!q.empty())
        {
            if(vis[u])
                break;
            l = q.front();
            q.pop();
            for(int i=0; i<r; i++)
            {
                int tmp = (l+cost[i])%10000;
                if(vis[tmp]==0)
                {
                    vis[tmp]=vis[l]+1;
                    q.push(tmp);
                }
            }
        }
        cout<<"Case "<<(++tc)<<": ";
        if(vis[u])
        {
            cout<<vis[u]<<endl;
        }
        else
        {
            cout<<"Permanently Locked"<<endl;
        }
    }
    return 0;
}

/*
Sample Input
0000 9999 1
1000
0000 9999 1
0001
5234 1212 3
1023 0101 0001
0 0 0

Sample Output
Case 1: Permanently Locked
Case 2: 9999
Case 3: 48
*/
