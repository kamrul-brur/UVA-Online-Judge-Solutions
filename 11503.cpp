/*
11503 - Virtual Friends
*/

#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
long int coun,arr[MAX],par[MAX];
map <string,long >mymap;

void make_set(long int n)
{
    par[n]=n;
    return;
}
long int find_set(long n)
{
    if(par[n]!= n)
    {
        par[n]=find_set(par[n]);
    }
    return par[n]=par[n];
}

long int find_set1(long n)
{
    if(par[n]!=n)
    {
        coun++;
        par[n]=find_set(par[n]);
    }
    return par[n]=par[n];
}
int main()
{
    long int i,j,len,k,node,test,x,y,n;
    string node1,node2;
    scanf("%ld",&test);
    while(test--)
    {
        scanf("%ld",&n);
        node=0;
        mymap.clear();
        memset(par,0,sizeof(par));
        for(i=0; i<MAX; i++)
        {
            arr[i]=1;
        }
        while(n--)
        {
            cin >> node1 >> node2;
            if(mymap.find(node1)==mymap.end())
            {
                node=node+1;
                mymap[node1]=node;
                par[node]=node;

            }
            if(mymap.find(node2)==mymap.end())
            {
                node=node+1;
                mymap[node2]=node;
                par[node]=node;

            }
            x = mymap[node1];
            y = mymap[node2];
            long ux,uy;
            ux=find_set(x);
            uy=find_set(y);
            if(ux==uy)
            {
                printf("%ld\n",arr[ux]);
            }
            else
            {
                par[ux]=uy;
                arr[uy]+=arr[ux];
                printf("%ld\n",arr[uy]);
            }

        }
    }
    return 0;
}
/*
Sample Input
1
3
Fred Barney
Barney Betty
Betty Wilma

Sample Output
2
3
4
*/
