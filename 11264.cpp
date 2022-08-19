/*
11264 - Coin Collector
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ans,x,y,n,t,sum;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ar[n];
        for(int i=0; i<n; i++)
        {
            cin>>ar[i];
        }
        sum = ar[0];
        ans=1;
        for(int i=1; i<n-1; i++)
        {
            if(sum+ar[i]<ar[i+1])
            {
                sum += ar[i];
                ans++;
            }
        }
        cout<<ans+1<<endl;
    }
    return 0;
}

/*
Sample Input
2
6
1 2 4 8 16 32
6
1 3 6 8 15 20

Sample Output
6
4
*/
