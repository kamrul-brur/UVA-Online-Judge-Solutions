/*
674 - Coin Change
*/
#include<bits/stdc++.h>
using namespace std;

int dp[6][7500];
int make;
int coin[]= {1,5,10,25,50};

int call(int i, int cnt)
{
    if(i>=5)
    {
        if(cnt==0)
            return 1;
        else
            return 0;
    }
    if(dp[i][cnt]!=-1)
        return dp[i][cnt];
    int ret1=0,ret2=0;
    if(cnt-coin[i]>=0)
        ret1=call(i,cnt-coin[i]);
    ret2=call(i+1,cnt);
    return dp[i][cnt]=ret1+ret2;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    while(cin>>make)
    {
        cout<<call(0,make)<<endl;
    }

}

/*
Sample Input
11
26

Sample Output
4
13
*/

