/*
11917 - Do Your Own Homework
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test, n, i;
    int cases = 0;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        char sub[101][50], in[50];
        int D[101], d;
        for(i = 0; i < n; i++)
            scanf("%s %d", &sub[i], &D[i]);
        scanf("%d %s", &d, in);
        printf("Case %d: ", ++cases);
        for(i = 0; i < n; i++)
        {
            if(!strcmp(sub[i], in))
            {
                if(d >= D[i])
                    puts("Yesss");
                else if(d+5 >= D[i])
                    puts("Late");
                else
                    puts("Do your own homework!");
                break;
            }
        }
        if(i == n)
            puts("Do your own homework!");
    }
    return 0;
}

/*
Sample Input
3
3
compiler 4
cplusplus 1
java 8
5
compiler
2
algorithm 3
math 9
4
math
2
java 8
ai 3
6
calculus

Sample Output
Case 1: Yesss
Case 2: Late
Case 3: Do your own homework!
*/
