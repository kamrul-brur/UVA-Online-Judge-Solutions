/*
562 - Dividing coins
*/

#include<bits/stdc++.h>
using namespace std;
#define SZ 50004

int dp[SZ], n, arr[102], s;


int main()
{
    int test, i, j;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        s = 0;
        for(i = 0; i<n; i++)
        {
            scanf("%d", &arr[i]);
            s += arr[i];
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(i = 0; i<n; i++)
            for(j = s; j>=arr[i]; j--)
                dp[j] += dp[j-arr[i]];


        int ret = (1<<20);
        for(i = s; i>=0; i--)
        {
            if(dp[i])
            {
                j = abs(i-(s-i));
                if(j < ret) ret = j;
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}

/*
Sample Input
2
3
2 3 5
4
1 2 4 6

Sample Output
0
1
*/
