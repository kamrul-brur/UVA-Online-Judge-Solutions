/*
11631 - Dark roads
*/

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,pair<int,int>>>p;
int parent[200001];
void initialize(int n)
{
    for(int i=0; i<n; i++)
    {
        parent[i]=i;
    }
}

int findd(int i)
{
    return (parent[i]==i)?i:findd(parent[i]);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n,m;
    while(scanf("%d %d",&n,&m)==2)
    {
        if(n==0 && m==0)break;
        initialize(n);
        p.clear();
        int total=0;
        for(int i=0; i<m; i++)
        {
            int x,y,c;
            scanf("%d %d %d",&x,&y,&c);
            p.push_back(make_pair(c,make_pair(x,y)));
            total+=c;
        }
        sort(p.begin(),p.end());
        int sum=0;
        for(int i=0; i<m; i++)
        {
            int px = findd(p[i].second.first);
            int py = findd(p[i].second.second);
            if(px!=py)
            {
                sum+=p[i].first;
                parent[py]=px;
            }
        }
        cout<<total-sum<<endl;
    }
    return 0;
}

/*
Sample Input
7 11
0 1 7
0 3 5
1 2 8
1 3 9
1 4 7
2 4 5
3 4 15
3 5 6
4 5 8
4 6 9
5 6 11
0 0

Sample Output
51

*/
