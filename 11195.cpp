/*
11195 - Another n-Queen Problem
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define M 1000007

int n;
string str[15];

int call(ll row,ll cur,ll left,ll right)
{
    if(row==n)
        return 1;
    int ret=0;
    ll all = cur|left|right;
    for(int i=0; i<n; i++)
    {
        ll te=(1ll<<i);
        if(str[row][i]=='.'&&!(te&all))
        {
            ret+=call(row+1,cur|te,(left|te)>>1,(right|te)<<1);
        }
    }
    return ret;
}

int main()
{
    int casee=1;
    while(cin>>n &&n)
    {
        for(int i=0; i<n; i++)
            cin>>str[i];
        cout<<"Case "<<casee++<<": "<<call(0,0,0,0)<<endl;
    }
    return 0;
}


/*
Sample Input
8
........
........
........
........
........
........
........
........
4
.*..
....
....
....
0

Sample Output
Case 1: 92
Case 2: 1
*/
