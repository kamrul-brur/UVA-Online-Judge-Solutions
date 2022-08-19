/*
10815 - Andy's First Dictionary
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    set<string>name;
    set<string>::iterator it;
    int i,len;
    char ar[222];
    while(gets(ar))
    {
        string str="";
        len=strlen(ar);

        for(i=0; i<=len; i++)
        {
            if(isalpha(ar[i]))
                str+=tolower(ar[i]);
            else if(str!="")
            {
                name.insert(str);
                str ="";
            }
        }
    }
    for(it=name.begin(); it!=name.end(); it++)
    {
        cout<<*it<<endl;
    }
    return 0;
}
/*
For this problem we've to take input from text file and save it in text file for proper visualization of output...

Sample Input
Adventures in Disneyland
Two blondes were going to Disneyland when they came to a fork in the
road. The sign read: "Disneyland Left."
So they went home.

Sample Output
a
adventures
blondes
came
disneyland
fork
going
home
in
left
read
road
sign
so
the
they
to
two
went
were
when

*/
