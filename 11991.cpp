/*
11991 - Easy Problem from Rujia Liu?
*/

#include<bits/stdc++.h>
using namespace std;

vector<int>vec[1000015];

int main()
{
    int n,m,val,k,q,v,i,j,z;
    while(cin>>n>>m)
    {
        for(i=0; i<100005; i++)
        {
            vec[i].clear();
        }
        for(j=0; j<n; j++)
        {
            cin>>q;
            vec[q].push_back(j+1);
        }
        for(z=0; z<m; z++)
        {
            cin>>k>>v;
            if(vec[v].size()<k)
            {
                cout<<0<<endl;
            }
            else
            {
                cout<<vec[v][k-1]<<endl;
            }
        }

    }
    return 0;
}
/*
Sample Input
8 4
1 3 2 2 4 3 2 1
1 3
2 4
3 2
4 2

Sample Output
2
0
7
0
*/
