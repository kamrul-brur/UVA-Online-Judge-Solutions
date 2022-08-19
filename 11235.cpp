/*
11235 - Frequent values
*/

#include<bits/stdc++.h>
using namespace std;

#define mx 100001
#define hhh 100008
#define max3(a,b,c) max(a,b)>max(b,c)? max(a,b): max(b,c)
int arr[mx];
int tree[mx*3];
int cnt[mx];
int start[mx];
map <int, int> mp;
void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node]=cnt[b];
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    init(left,b,mid);
    init(right, mid+1, e);
    tree[node]=max(tree[left], tree[right]);
}

int query(int node, int b, int e, int i, int j)
{
    if(i>e || j<b)
    {
        return 0;
    }
    if(b>=i && e<=j)
        return tree[node];
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    int p1 = query(left,b,mid,i,j);
    int p2 = query(right,mid+1,e,i,j);
    return max(p1,p2);
}

int main()
{
    int n,q;
    while(scanf("%d",&n)==1 && n!=0)
    {
        cin>>q;
        for(int i=1; i<=n; i++)
        {
            cin>>arr[i];
            mp[arr[i]]++;
        }

        int y = -hhh,k;
        for(int i=1; i<=n; i++)
        {
            int x = mp[arr[i]];
            cnt[i]=x;///initializing counts value
            if(arr[i]!=y)
            {
                k=i;
                y = arr[i];
            }
            start[i]=k;
        }
        init(1,1,n);
        for(int i=1; i<=q; i++)
        {
            int low,high,cnt1,cnt2,cnt3;
            cin>>low>>high;
            if(arr[low]!=arr[high])
            {
                int k = start[low]+cnt[low];
                cnt1 = k- low;
                cnt2=high-start[high]+1;
                cnt3 = query(1,1,n,k,start[high]-1);
                printf("%d\n",max3(cnt1,cnt2,cnt3));
            }
            else
                cout<<high-low+1<<endl;
        }
        memset(tree,0,sizeof(tree));
        memset(cnt,0,sizeof(tree));
        memset(start,0,sizeof(tree));
        mp.clear();

    }
    return 0;
}

/*
Sample Input
10 3
-1 -1 1 1 1 1 3 10 10 10
2 3
1 10
5 10
0

Sample Output
1
4
3
*/
