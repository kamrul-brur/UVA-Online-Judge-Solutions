/*
11085 - Back to the 8-Queens
*/

#include<bits/stdc++.h>
using namespace std;

int queens[8], path[8];

bool valid(int r, int c)
{
    for(int j = 0; j < r; j++)
    {
        if(c == path[j]) return false;
        if(abs(r - j) == abs(c - path[j])) return false;
    }
    return true;
}

int searchhhh(int n)
{
    if(n == 8) return 0;

    int total = 100000;

    for(int i = 0; i < 8; i++)
        if(valid(n, i))
        {
            path[n] = i;
            total = min(total, i == queens[n]? searchhhh(n + 1) : 1 + searchhhh(n + 1));
        }

    return total;
}

int main()
{
    for(int T = 1;; T++)
    {
        for(int i = 0; i < 8; i++)
        {
            if(scanf("%d", &queens[i]) == -1) return 0;
            queens[i]--;
            path[i] = queens[i];
        }

        printf("Case %d: %d\n", T, searchhhh(0));
    }
    return 0;
}
/*
Sample Input
1 2 3 4 5 6 7 8
1 1 1 1 1 1 1 1

Sample Output
Case 1: 7
Case 2: 7

*/
