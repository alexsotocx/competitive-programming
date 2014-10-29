#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while(scanf("%d\n",&n)==1 && n)
    {
        vector<string>x =vector<string>(n,"");
        int max=0;
        int *spaces=new int [n];
        for(int i=0;i<n;i++){
            getline(cin,x[i]);
            spaces[i]=count(x[i].begin(),x[i].end(),' ');
            max = (max>spaces[i])?spaces[i]:max;
        }
        int ret=0;
        for(int i=0;i<n;i++)
            ret+=spaces[i]-max;
        cout<<ret<<endl;


    }
}
