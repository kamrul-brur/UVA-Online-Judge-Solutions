/*
459 - Graph Connectivity
*/
#include<bits/stdc++.h>
using namespace std;
typedef vector<int>v_s;
typedef vector<v_s>m_t;
void dfs(int node,const m_t&mat,v_s&vis)
{
    if(vis[node])
        return;
    vis[node]=true;
    for(int i=0; i<(int)mat[node].size(); i++)
    {
        int v = mat[node][i];
        if(vis[v]==false)
        {
            dfs(v,mat,vis);
        }
    }
}
int main()
{
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    int t;
    scanf("%d\n\n",&t);
    char ch;
    string s;
    bool blank =false;
    while(t--)
    {
        cin>>ch;
        int n = ch-'A'+1;
        cin.ignore();

        v_s vis(n,false);
        m_t mat(n);

        while(getline(cin, s) && s != "")
        {
            mat[s[0]-'A'].push_back(s[1]-'A');
            mat[s[1]-'A'].push_back(s[0]-'A');
        }
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            if(vis[i]==false)
            {
                cnt++;
                dfs(i,mat,vis);
            }
        }
        cout<<cnt<<endl;
        if(t)
        {
            printf("\n");
        }
    }
    return 0;
}
/*
Sample Input
1
E
AB
CE
DB
EC

Sample Output
2
*/
