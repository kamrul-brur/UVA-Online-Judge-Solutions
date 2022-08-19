/*
11228 - Transportation system.
*/

#include<bits/stdc++.h>
using namespace std;
vector<pair<double,pair<long,long>>>p;
const int MX = 1e6+5;
long x[1005],y[1005];
long parent[MX];
int n,r;
long findd(long i)
{
    return (parent[i]==i)?i:findd(parent[i]);
}

void initializer(long n)
{
    for(int i=0; i<n; i++)
    {
        parent[i]=i;
    }
}
int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int t,tc=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>r;
        initializer(n);
        p.clear();
        for(int i=0; i<n; i++)
        {
            cin>>x[i]>>y[i];
        }
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                double diff = sqrt((x[i]-x[j])*(x[i]-x[j])*1.0+(y[i]-y[j])*(y[i]-y[j])*1.0);
                p.push_back(make_pair(diff,make_pair(i,j)));
            }
        }
        sort(p.begin(),p.end());
        double rail=0,road=0,state=1;
        for(int i=0; i<p.size(); i++)
        {
            int px = findd(p[i].second.first);
            int py = findd(p[i].second.second);
            double cost = p[i].first;
            if(px!=py && cost>r*1.0)
            {
                parent[px]=py;
                rail+=cost;
                state++;
            }
            else if(px!=py)
            {
                parent[px]=py;
                road+=cost;
            }
        }
        long long road_len = floor(road+.5);
        long long rail_len = floor(rail+.5);
        cout<<"Case #"<<(++tc)<<": "<<state<<" "<<road_len<<" "<<rail_len<<endl;
    }
    return 0;
}

/*
Sample Input
3
3 100
0 0
1 0
2 0
3 1
0 0
100 0
200 0
4 20
0 0
40 30
30 30
10 10

Sample Output
Case #1: 1 2 0
Case #2: 3 0 200
Case #3: 2 24 28
*/

