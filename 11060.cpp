/*
11060 - Beverages
*/

#include<bits/stdc++.h>
using namespace std;

typedef set<int>st;
map<string,int>mp1;
map<int,string>mp2;
map<int,st>result;
map<int,st>::iterator two;
vector<int>ans;
st::iterator sit;

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int n,m,x,y,tc=0;
    string s1,s2;
    while(cin>>n)
    {
        mp1.clear();
        mp2.clear();
        ans.clear();
        for(int i=1; i<=n; i++)
        {
            cin>>s1;
            mp1[s1]=i;
            mp2[i]=s1;
            result[i].insert(0);
        }
        cin>>m;
        for(int i=1; i<=m; i++)
        {
            cin>>s1>>s2;
            x = mp1[s2];
            y = mp1[s1];
            result[x].insert(y);
        }
        while(result.size()!=0)
        {
            for(two=result.begin(); two!=result.end(); two++)
            {
                if(two->second.size()==1)
                {
                    x = two->first;
                    result.erase(x);
                    break;
                }
            }
            ans.push_back(x);
            for(two=result.begin(); two!=result.end(); two++)
            {
                if(two->second.size()>1)
                {
                    sit = two->second.find(x);
                    if(sit!=two->second.end())
                    {
                        two->second.erase(x);
                    }
                }
            }
        }
        cout<<"Case #"<<(++tc)<<": Dilbert should drink beverages in this order:";
        for(int i=0; i<n; i++)
        {
            cout<<" "<<mp2[ans[i]];
        }
        cout<<".\n\n";
    }
    return 0;
}
/*
Sample Input
3
vodka
wine
beer
2
wine vodka
beer wine
5
wine
beer
rum
apple-juice
cachaca
6
beer cachaca
apple-juice beer
apple-juice rum
beer rum
beer wine
wine cachaca
10
cachaca
rum
apple-juice
tequila
whiskey
wine
vodka
beer
martini
gin
11
beer whiskey
apple-juice gin
rum cachaca
vodka tequila
apple-juice martini
rum gin
wine whiskey
apple-juice beer
beer rum
wine vodka
beer tequila

Sample Output
Case #1: Dilbert should drink beverages in this order: beer wine vodka.

Case #2: Dilbert should drink beverages in this order: apple-juice beer wine rum cachaca.

Case #3: Dilbert should drink beverages in this order: apple-juice wine vodka beer rum cachaca tequila whiskey martini gin.
*/
