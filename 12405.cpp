/*
12405 - Scarecrow
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    for(int i=0; i<test; i++)
    {
        int n,cnt=0;
        cin>>n;
        string s;
        cin>>s;
        for(int k=0; k<n; ++k)
        {
            if((s[k]=='.')&&(k<n))
            {
                s[k+1]='#';
                cnt++;
                k+=2;
            }
        }
        cout<<"Case "<<i+1<<": "<<cnt<<endl;
        s.erase(s.begin(), s.end());
    }
    return 0;
}
/*
Sample Input
3
3
.#.
11
...##....##
2
##

Sample Output
Case 1: 1
Case 2: 3
Case 3: 0
*/
