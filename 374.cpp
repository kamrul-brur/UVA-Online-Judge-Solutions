/*
374 - Big Mod
*/

#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int bigmod(int b,int p,int m);

int main()
{
    int b,p,m;
    while(scanf("%d %d %d",&b,&p,&m)==3)
    {
        int ans = bigmod(b,p,m);
        cout<<ans<<endl;
    }
}

int bigmod(int b,int p,int m)
{
    if (p == 0)
        return 1;
    else if (p%2 == 0)
    {

        int x=bigmod(b,p/2,m);
        return (x*x)%m;
    }
    else
        return ((b % m) * bigmod(b,p-1,m)) % m;
}

/*
Sample Input
3
18132
17
17
1765
3
2374859
3029382
36123

Sample Output
13
2
13195
*/
