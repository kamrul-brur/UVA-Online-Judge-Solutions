/*
10812 - Beat the Spread!
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s,d;
    int a;
    int test;

    while(scanf("%d",&test)==1)
    {
        while(test--)
        {
            scanf("%d %d",&s,&d);
            int temp=0;
            a=0;
            temp = s;
            if(d>s||(s-d)%2!=0)
            {
                printf("impossible\n");
            }
            else
            {
                a = (s-d)/2;
                s = s-a;
                d = temp-s;
                printf("%d %d\n",max(s,d),min(s,d));
            }
        }
    }
    return 0;
}
/*
Sample Input
2
40 20
20 40

Sample Output
30 10
impossible
*/
