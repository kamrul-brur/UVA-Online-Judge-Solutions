/*
11900 - Boiled Eggs
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test,k;
    cin>>test;
    for(k=1; k<=test; k++)
    {
        int n,p,q,cnt=0,sum=0;

        cin>>n>>p>>q;
        int ar[n];
        for(int i=0; i<n; i++)
        {
            cin>>ar[i];
        }
        for(int i=0; i<n; i++)
        {
            sum = sum + ar[i];

            if(sum>q)
            {
                break;
            }
            else
            {
                cnt++;
            }
        }
        if(cnt>p)
        {
            printf("Case %d: %d\n",k,p);
        }
        else
        {
            printf("Case %d: %d\n",k,cnt);
        }
    }
    return 0;
}
/*
Sample Input
2
3 2 10
1 2 3
4 5 5
4 4 5 5

Sample Output
Case 1: 2
Case 2: 1
*/
