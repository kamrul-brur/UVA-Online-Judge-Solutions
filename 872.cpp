/*
872 - Ordering
*/
#include<bits/stdc++.h>
using namespace std;

string s;
int mat[26][26],n;
bool found;
char ans[26],vis[26]= {0};
void dfs(int idx)
{
    if(idx==n)
    {
        found=true;
        cout<<ans[0];
        for(int i=1; i<n; i++)
        {
            cout<<" "<<ans[i];
        }
        cout<<'\n';
        return;
    }
    int i,j;
    for(i=0; i<n; i++)
    {
        if(!vis[i])
        {
            for(j=0; j<idx; j++)
            {
                if(mat[s[i]-'A'][ans[j]-'A'])
                    break;
            }
            if(j==idx)
            {
                ans[idx]=s[i];
                vis[i]=1;
                dfs(idx+1);
                vis[i]=0;
            }
        }
    }

}
int main()
{
    //freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int t;
    bool first=false;
    cin>>t;
    string line;
    getchar();
    while(t--)
    {
        getchar();
        getline(cin,line);
        stringstream sin;
        sin<<line;
        s="";
        while(sin>>line)
            s+=line;
        sort(s.begin(),s.end());
        memset(mat,0,sizeof(mat));
        getline(cin,line);
        sin.clear();
        sin<<line;
        while(sin>>line)
        {
            int x = line[0]-'A';
            int y = line[2]-'A';
            mat[x][y]=1;
        }
        n = s.length();
        found=false;
        dfs(0);
        if(!found)
        {
            cout<<"NO"<<endl;
        }
        if(t>0){
            cout<<endl;
        }
    }
    return 0;
}

/*
Sample Input
1

A B F G
A<B B<F

Sample Output
A B F G
A B G F
A G B F
G A B F
*/
