/*
200 - Rare Order
*/

#include<bits/stdc++.h>
using namespace std;
char mat[5000][21];

int main()
{

    char s[21];
    int idx=0;
    while(cin>>s)
    {
        if(s[0]=='#')
            break;
        int len = strlen(s);
        for(int i=0; i<len; i++)
        {
            mat[idx][i]=s[i];
        }
        while(len!=21)
        {
            mat[idx][len]='a';
            len++;
        }
        idx++;
    }
    vector<bool>vis(26,false);
    for(int i=0; i<21; i++)
    {
        for(int j=0; j<idx; j++)
        {
            int val = mat[j][i]-'A';
            if(val>=0 && val<=25 && vis[val]==false)
            {
                vis[val]=true;
                cout<<mat[j][i];
            }
        }
    }
    cout<<endl;
    return 0;
}
/*
Sample Input
XWY
ZX
ZXY
ZXW
YWWX
#

Sample Output
XZYW
*/
