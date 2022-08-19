/*
11849 - CD
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, a;
    while(scanf("%d%d", &n, &m))
    {
        if(n==0 && m==0) break;
        int cnt=0;
        map<int, int> p;

        for(int i=0; i<n; i++)
        {
            scanf("%d", &a);
            p[a]=1;
        }

        for(int i=0; i<m; i++)
        {
            scanf("%d", &a);
            if(p[a]==1) cnt++;
        }
        printf("%d\n", cnt);
        p.clear();
    }
    return 0;
}
/*
Sample Input
3 3
1
2
3
1
2
4
0 0

Sample Output
2
*/
