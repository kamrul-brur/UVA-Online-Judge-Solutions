/*
12086 - Potentiometers
*/
#include<bits/stdc++.h>
using namespace std;

#define MAXX 200005

int cnt, sum[MAXX * 4];


void insert_update(int idx, int st, int ed, int pos, int value)
{
    if(st == pos && pos == ed)
    {
        sum[idx] = value;
        return;
    }

    int l = idx<<1;
    int r = l + 1;
    int mid = (st + ed) / 2;

    if(pos <= mid) insert_update(l, st, mid, pos, value);
    else insert_update(r, mid+1, ed, pos, value);

    sum[idx] = sum[l] + sum[r];
}


int quer(int idx, int st, int ed, int i, int j)
{
    if(i==st && j==ed) return sum[idx];

    int l = idx<<1;
    int r = l + 1;
    int mid = (st + ed) / 2;


    if(j<=mid)
    {
        return quer(l, st, mid, i, j);
    }
    else if(i > mid)
    {
        return quer(r, mid+1, ed, i, j);
    }
    else return quer(l, st, mid, i, mid) + quer(r, mid+1, ed, mid+1, j);


}



int main()
{
    //read();

    int cntt = 0;

    int num;
    char query[5];
    int p, q;
    while(1)
    {
        cin>>cnt;
        if(!cnt) break;
        memset(sum, 0,sizeof(sum));
        for(int i=1; i<=cnt; i++)
        {
            cin>>num;
            insert_update(1, 1, cnt, i, num);
        }

        if(cntt) printf("\n");

        printf("Case %d:\n", ++cntt);

        while(1)
        {
            cin>>query;
            if(query[0] == 'E') break;

            cin>>p;
            cin>>q;

            if(query[0] == 'M')
            {
                printf("%d\n", quer(1, 1, cnt, p, q));
            }
            else
            {
                insert_update(1, 1, cnt, p, q);
            }
        }
    }
    return 0;
}
/*
Sample Input
3
100
100
100
M 1 1
M 1 3
S 2 200
M 1 2
S 3 0
M 2 3
END
10
1
2
3
4
5
6
7
8
9
10
M 1 10
END
0
Sample Output
Case 1:
100
300
300
200

Case 2:
55
*/
