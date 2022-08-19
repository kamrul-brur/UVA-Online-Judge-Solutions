/*
247 - Calling Circles
*/

#include<bits/stdc++.h>
using namespace std;
#define MX 30

map<string,int>names;
vector<string>rnames;
int n,m,nameslen=0,tc=0;
vector<int>edge[MX];
vector<int>redge[MX];
vector<int>route;
int vis[MX];
int comp[MX];
bool check =false;
void dfs1(int u)
{
    vis[u]=true;
    for(int i=0; i<edge[u].size(); i++)
    {
        int v = edge[u][i];
        if(!vis[v])
        {
            dfs1(v);
        }
    }
    route.push_back(u);
}
void dfs2(int u,int c)
{
    vis[u]=false;
    comp[u]=c;
    for(int i=0; i<redge[u].size(); i++)
    {
        int v = redge[u][i];
        if(vis[v])
        {
            dfs2(v,c);
        }
    }
}
void reset_all()
{
    for(int i=0; i<MX; i++)
    {
        edge[i].clear();
        redge[i].clear();
    }
    names.clear();
    rnames.clear();
    route.clear();
    nameslen=0;
    memset(vis,false,sizeof(vis));
}
void assignnumber(string s)
{
    if(!names[s])
    {
        ++nameslen;
        names[s]=nameslen;
        rnames.push_back(s);
    }
}

void print_ans(int scc)
{
    if(check)
    {
        printf("\n");
    }
    check=true;
    printf("Calling circles for data set %d:\n",++tc);
    bool space;
    for(int i=1; i<=scc; i++)
    {
        space=false;
        for(int j=0; j<n; j++)
        {
            if(comp[j+1]==i)
            {
                if(space)
                    cout<<", ";
                space=true;
                cout<<rnames[j];
            }
        }
        printf("\n");
    }
}

int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(scanf("%d %d",&n,&m)==2)
    {
        if(n==0 && m==0)
            break;
        reset_all();
        string name1,name2;
        for(int i=0; i<m; i++)
        {
            cin>>name1>>name2;
            assignnumber(name1);
            assignnumber(name2);
            edge[names[name1]].push_back(names[name2]);
            redge[names[name2]].push_back(names[name1]);
        }
        for(int i=1; i<=nameslen; i++)
        {
            if(!vis[i])
            {
                dfs1(i);
            }
        }
        int scc=0;
        for(int i=route.size()-1; i>=0; i--)
        {
            if(vis[route[i]])
            {
                dfs2(route[i],++scc);
            }
        }
        print_ans(scc);
    }
    return 0;
}

/*
5 6
Ben Alexander
Alexander Dolly
Dolly Ben
Dolly Benedict
Benedict Dolly
Alexander Aaron
14 34
John Aaron
Aaron Benedict
Betsy John
Betsy Ringo
Ringo Dolly
Benedict Paul
John Betsy
John Aaron
Benedict George
Dolly Ringo
Paul Martha
George Ben
Alexander George
Betsy Ringo
Alexander Stephen
Martha Stephen
Benedict Alexander
Stephen Paul
Betsy Ringo
Quincy Martha
Ben Patrick
Betsy Ringo
Patrick Stephen
Paul Alexander
Patrick Ben
Stephen Quincy
Ringo Betsy
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Quincy Martha
0 0


Sample Output
Calling circles for data set 1:
Ben, Alexander, Dolly, Benedict
Aaron
Calling circles for data set 2:
John, Betsy, Ringo, Dolly
Aaron
Benedict
Paul, George, Martha, Ben, Alexander, Stephen, Quincy, Patrick
*/
