/*
11747 - Heavy Cycle Edges
*/

#include<bits/stdc++.h>
using namespace std;
#define MX 1005
struct node
{
    int x,y,cost;
};
vector<pair<int,pair<int,int>>>p;
vector<int>ans;
vector<int>parent(MX);

void initialize(int n)
{
    for(int i=0; i<=n; i++)
    {
        parent[i]=i;
    }
    ans.clear();
    p.clear();
}
int findd(int i)
{
    return (parent[i]==i)?i:findd(parent[i]);
}

int main()
{
    int n,m;
    while(cin>>n>>m,!(m==0 && n==0))
    {
        initialize(n);
        for(int i=0; i<m; i++)
        {
            int x,y,c;
            cin>>x>>y>>c;
            p.push_back(make_pair(c,make_pair(x,y)));
        }
        sort(p.begin(),p.end());
        for(int i=0; i<p.size(); i++)
        {
            int px = findd(p[i].second.first);
            int py = findd(p[i].second.second);
            if(px!=py)
            {
                parent[px]=py;
            }
            else
            {
                ans.push_back(p[i].first);
            }
        }
        sort(ans.begin(),ans.end());
        if(ans.size()==0){
            cout<<"forest"<<endl;
        }
        else{
            cout<<ans[0];
            for(int i=1;i<ans.size();i++){
                cout<<" "<<ans[i];
            }cout<<endl;
        }
    }
    return 0;
}
/*
Sample Input
3 3
0 1 1
1 2 2
2 0 3
4 5
0 1 1
1 2 2
2 3 3
3 1 4
0 2 0
3 1
0 1 1
0 0

Sample Output
3
2 4
forest
*/

