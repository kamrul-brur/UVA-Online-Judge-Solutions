/*
12032 - The Monkey and the Oiled Bamboo
*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int test;
    cin>>test;
    for(int i=1; i<=test; i++)
    {
        int n,temp;
        cin>>n;
        int ar[n+1];
        ar[0]=0;
        for(int j=1; j<=n; j++)
        {
            cin>>ar[j];
        }
        temp =0;
        for(int j=1; j<=n; j++)
        {
            if((ar[j]-ar[j-1])>temp)
            {
                temp = ar[j]-ar[j-1];
            }
        }
        int ans;
        ans = temp;

        for(int j=1; j<=n; j++)
        {
            if((ar[j]-ar[j-1])==temp)
            {
                temp--;
            }
            else if((ar[j]-ar[j-1])>temp)
            {
                ans++;
                break;
            }
        }
        cout<<"Case "<<i<<": "<<ans<<endl;

    }
    return 0;
}
/*
Sample Input
2
5
1 6 7 11 13
4
3 9 10 14

Sample Output
Case 1: 5
Case 2: 6
*/
