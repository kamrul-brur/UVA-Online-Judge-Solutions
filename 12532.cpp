/*
12532 - Interval Product
*/
#include<bits/stdc++.h>
using namespace std;
int z1, z2, node[100010*4];
void insert(int idx, int st, int ed, int s, int e, int val)
{
    if(st==s && ed==e)
    {
        if(val>0) node[idx]=1;
        else if(val<0) node[idx]=-1;
        else node[idx]=0;
        return;
    }
    int mid=(st+ed)>>1, lft=idx<<1, rgt=lft|1;
    if(e<=mid) insert(lft, st, mid, s, e, val);
    else if(s>mid) insert(rgt, mid+1, ed, s, e, val);
    else
    {
        insert(lft, st, mid, s, mid, val);
        insert(rgt, mid+1, ed, mid+1, e, val);
    }
    node[idx] = node[lft] * node[rgt];
    return;
}

int query(int idx, int st, int ed, int s, int e)
{
    if(st==s && ed==e)
    {
        return node[idx];
    }
    int mid=(st+ed)>>1, lft=idx<<1, rgt=lft|1;
    if(e<=mid) return query(lft, st, mid, s, e);
    else if(s>mid) return query(rgt, mid+1, ed, s, e);
    else return query(lft, st, mid, s, mid)*query(rgt, mid+1, ed, mid+1, e);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc,kk=1, n, q, x, y;
    char c;
    string s;
    while(cin>>n>>q)
    {
        for(int i=1; i<=n*4; i++)
            node[i]=1;

        for(int i=1; i<=n; i++)
        {
            cin>>x;
            insert(1, 1, n, i, i, x);
        }
        while(q--)
        {
            cin>>c>>x>>y;
            if(c=='C')
                insert(1, 1, n, x, x, y);
            else
            {
                z1 = query(1, 1, n, x, y);
                if(z1==0)
                    cout<<"0";
                else if(z1<0)
                    cout<<"-";
                else cout<<"+";
            }
        }
        cout<<endl;
    }
    return 0;
}

/*
Sample Input
4 6
-2 6 0 -1
C 1 10
P 1 4
C 3 7
P 2 2
C 4 -5
P 1 4
5 9
1 5 -2 4 3
P 1 2
P 1 5
C 4 -5
P 1 5
P 4 5
C 3 0
P 1 5
C 4 -5
C 4 -5

Sample Output
0+-
+-+-0
*/
