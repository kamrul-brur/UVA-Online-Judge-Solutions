/*
11995 - I Can Guess the Data Structure!
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test,a,b,d,cq,cstk,cpq,i;
    while(scanf("%d",&test)==1)
    {
        queue<int>q;
        stack<int>stk;
        priority_queue<int>pq;
        d=0;
        cq=0;
        cstk=0;
        cpq=0;
        for(i=0; i<test; i++)
        {
            scanf("%d %d",&a,&b);
            if(a==1)
            {
                q.push(b);
                stk.push(b);
                pq.push(b);
            }
            if(a==2)
            {
                ++d;
                if(!q.empty() && b==q.front())
                {
                    ++cq;
                    q.pop();
                }
                if(!stk.empty() && b==stk.top())
                {
                    ++cstk;
                    stk.pop();
                }
                if(!pq.empty() && b==pq.top())
                {
                    ++cpq;
                    pq.pop();
                }
            }
        }
        if((d==cq && d==cstk) || (d==cq && d==cpq) || (d==cstk && d==cpq) || (d==cq && d==cstk && d==cpq))
            printf("not sure\n");
        else if(d==cq)
            printf("queue\n");
        else if(d==cstk)
            printf("stack\n");
        else if(d==cpq)
            printf("priority queue\n");
        else
            printf("impossible\n");
    }
    return 0;
}
/*
Sample Input
6
1 1
1 2
1 3
2 1
2 2
2 3
6
1 1
1 2
1 3
2 3
2 2
2 1
2
1 1
2 2
4
1 2
1 1
2 1
2 2
7
1 2
1 5
1 1
1 3
2 5
1 4
2 4

Sample Output
queue
not sure
impossible
stack
priority queue
*/
