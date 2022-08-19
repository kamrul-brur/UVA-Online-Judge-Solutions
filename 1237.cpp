/*
1237 - Expert Enough?
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m, p;
        int l[10000], h[10000];
        int i;
        char name[10000][25];
        cin>>n;
        for(i = 0; i < n; i++)
            cin>>name[i]>>l[i]>>h[i];
        cin>>m;
        while(m--) {
            cin>>p;
            int cnt = 0, mi;
            for(i = 0; i < n; i++) {
                if(l[i] <= p && p <= h[i])
                    cnt++, mi = i;
                if(cnt > 1) break;
            }
            if(cnt == 1)
                puts(name[mi]);
            else
                puts("UNDETERMINED");
        }
        if(t)
            puts("");
    }
    return 0;
}
/*
Sample Input
1
4
HONDA 10000 45000
PEUGEOT 12000 44000
BMW 30000 75900
CHEVROLET 7000 37000
4
60000
7500
5000
10000

Sample Output
BMW
CHEVROLET
UNDETERMINED
UNDETERMINED
*/
