/*
11367 - Full Tank?
*/

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int dest;
    int fuel;
    int cost;

    node (int a,int b,int c)
    {
        dest=a;
        fuel=b;
        cost=c;
    }
};

bool operator < (node a,node b)
{
    return a.cost > b.cost;
}

typedef vector<node>ve;
typedef vector<ve>vve;

int memo[1005][105];
int p[1005];

int main()
{

    int n,m,q,i,u,v,w,c,s,t,res,u1,v1,w1;

    while (scanf("%d %d",&n,&m)!=EOF)
    {
        for (i=0; i<n; i++)
            scanf("%d",&p[i]);

        vve G(n);

        while (m--)
        {
            scanf("%d %d %d",&u,&v,&w);
            G[u].push_back(node(v,w,0));
            G[v].push_back(node(u,w,0));
        }

        cin>>q;

        while (q--)
        {
            priority_queue<node>pq;
            memset(memo,-1,sizeof(memo));
            cin>>c>>s>>t;
            pq.push(node(s,0,0));
            res = -1;

            while (!pq.empty())
            {
                u = pq.top().dest;
                v = pq.top().fuel;
                w = pq.top().cost;
                //cout<<u<<" "<<v<<" "<<w<<endl;
                //cout<<endl;
                pq.pop();

                if (u == t)
                {
                    res = w;
                    break;
                }

                if (memo[u][v] != -1)
                    continue;
                memo[u][v] = w;

                if (v < c)
                    pq.push(node(u,v+1,w+p[u]));
                for (i=0; i<G[u].size(); i++)
                {
                    u1=G[u][i].dest;
                    v1=G[u][i].fuel;
                    w1=G[u][i].cost;

                    if (v >=v1)
                    {
                        pq.push(node(u1,v-v1,w));
                    }

                }

            }
            if (res == -1)
                cout<<"impossible"<<endl;
            else
                cout<<res<<endl;
        }
    }
    return 0;
}

/*
Sample Input
5 5
10 10 20 12 13
0 1 9
0 2 8
1 2 1
1 3 11
2 3 7
2
10 0 3
20 1 4

Sample Output
170
impossible
*/
