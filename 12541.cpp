/*
12541 - Birthdates
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int date,month,year,temp,test;
    vector<int>v;
    vector<string>s;
    char name[20];
    cin>>test;
    for(int i=0; i<test; i++)
    {
        cin>>name;
        s.push_back(name);
        cin>>date>>month>>year;
        temp = 10000*year+100*month+date;
        v.push_back(temp);
    }
    int minv = v[0];
    vector<string>young;
    for(int i=1; i<v.size(); i++)
    {
        if(minv<v[i])
        {
            minv=v[i];
            young.push_back(s[i]);

        }
    }
    int siz_y = young.size()-1;
    cout<<young[siz_y]<<endl;
    vector<string>old;
    int maxv= v[0];
    for(int i=1; i<v.size(); i++)
    {
        if(maxv>v[i])
        {
            maxv=v[i];
            old.push_back(s[i]);

        }
    }
    int siz_o = old.size()-1;
    cout<<old[siz_o]<<endl;
}
/*
Sample Input
5
Mickey 1 10 1991
Alice 30 12 1990
Tom 15 8 1993
Jerry 18 9 1990
Garfield 20 9 1990

Sample Output
Tom
Jerry
*/
