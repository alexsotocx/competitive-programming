#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    int n,t1,t2,f,att,c1,c2,c3;
    cin>>n;
    int x[3];
    int i=0;
    while(n-- && cin>>t1>>t2>>f>>att>>x[0]>>x[1]>>x[2])
    {
        sort(x,x+3);
        int ans = t1+t2+f+att+(x[2]+x[1])/2;
        if(ans>=90) cout<<"Case "<<++i<<": A"<<endl;
        else if(ans>= 80 && ans< 90) cout<<"Case "<<++i<<": B"<<endl;
        else if(ans>= 70 && ans < 80) cout<<"Case "<<++i<<": C"<<endl;
        else if(ans>= 60 && ans< 70) cout<<"Case "<<++i<<": D"<<endl;
        else cout<<"Case "<<++i<<": F"<<endl;
    }
    return 0;
}
