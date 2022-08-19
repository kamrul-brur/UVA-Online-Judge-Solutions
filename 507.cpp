/*
507 - Jill Rides Again
*/
#include<bits/stdc++.h>
using namespace std;
const int MX = 20005;
int ar[MX],n;
int main()
{
    int t;
    scanf("%d",&t);
    for(int j=1; j<=t; j++)
    {
        scanf("%d",&n);
        n--;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&ar[i]);
        }
        int ans=INT_MIN,sum=0;
        int start,endd,s=1;
        for(int i=1; i<=n; i++)
        {
            sum+=ar[i];
            if(ans<sum ||(ans==sum && endd-start<i-s))
            {
                ans = sum;
                start=s;
                endd=i;
            }

            if(sum<0)
            {
                sum=0;
                s=i+1;
            }
        }
        if(ans>0)
        {
            printf("The nicest part of route %d is between stops %d and %d\n",j,start,endd+1);
        }
        else
            printf("Route %d has no nice parts\n",j);
    }
    return 0;
}

/*
Sample Input
3
3
-1
6
10
4
-5
4
-3
4
4
-4
4
-5
4
-2
-3
-4

Sample Output
The nicest part of route 1 is between stops 2 and 3
The nicest part of route 2 is between stops 3 and 9
Route 3 has no nice parts
*/
