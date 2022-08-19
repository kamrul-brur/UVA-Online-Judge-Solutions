/*
12210 - A Match Making Problem
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int b,s,a,k=1;
    while(cin>>b>>s)
    {
        if(b==0 && s==0)break;
        vector<int>v1;
        vector<int>v2;
        for(int i=0; i<b; i++)
        {
            cin>>a;
            v1.push_back(a);
        }
        for(int i=0; i<s; i++)
        {
            cin>>a;
            v2.push_back(a);
        }
        if(b<=s)
        {
            cout<<"Case "<<k++<<": "<<0<<endl;
        }
        else
        {
      cout<<"Case "<<k++<<": "<<b-s<<" "<< *min_element(v1.begin(), v1.end())<<endl;
        }

    }
    return 0;
}
/*
Sample Input
4 4
26
25
2
21
35
25
23
24
1 2
20
30
40
4 2
5
5
10
15
20
18
0 0

Sample Output
Case 1: 0
Case 2: 0
Case 3: 2 5
*/
