/*
11875 - Brick Game
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    for(int k=1; k<=test; k++)
    {
        int n;
        cin>>n;
        int ar[n];
        for(int i=0; i<n; i++)
        {
            cin>>ar[i];
        }

        sort(ar, ar+n);
        int ans = ceil(n/2);
        printf("Case %d: %d\n",k,ar[ans]);
    }
    return 0;
}
/*
Sample Input
2
5 19 17 16 14 12
5 12 14 16 17 18

Sample Output
Case 1: 16
Case 2: 16
*/
