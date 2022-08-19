/*
11777 - Automate the Grades
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    for(int k=1; k<=test; k++)
    {
        int sum=0;
        int ar[3];
        int a,b,c,d,avg;
        cin>>a>>b>>c>>d>>ar[0]>>ar[1]>>ar[2];
        sort(ar, ar+3);
        avg = (ar[2]+ar[1])/2;
        sum = a+b+c+d+avg;
        if(sum>=90)printf("Case %d: A\n",k);
        else if(sum>=80 && sum<90)printf("Case %d: B\n",k);
        else if(sum>=70 && sum<80)printf("Case %d: C\n",k);
        else if(sum>=60 && sum<70)printf("Case %d: D\n",k);
        else
            printf("Case %d: F\n",k);
    }
    return 0;
}
/*
Sample Input
3
15 18 25 8 15 17 12
20 20 30 10 20 20 20
20 20 30 10 18 0 0

Sample Output
Case 1: B
Case 2: A
Case 3: B
*/
