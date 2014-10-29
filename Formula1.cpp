#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
class timep
{
public:
    int min;
    int ms;
    int sec;
    string name2;
public:
    timep(int a,int b,int c, string ps)
    {
        min=a;
        sec=b;
        ms=c;
        name2=ps;
    }


};

 bool comp(const timep &a, const timep &b){
	if (a.min != b.min)
		return a.min < b.min;
	else if (a.sec != b.sec)
		return a.sec < b.sec;
	else if (a.ms != b.ms)
		return a.ms < b.ms;
	else
		return strcasecmp(a.name2.c_str(),b.name2.c_str());
}


int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        //priority_queue<timep,vector<timep>,mycomparison> q;
        vector<timep>q;
        int aux=n;
        while(n--)
        {
            string nom;
            cin>>nom;
            int m,s,ms;
            scanf(" : %d min %d sec %d ms",&m,&s,&ms);
            q.push_back(timep(m,s,ms,nom));
        }
        int cases = 0;

        sort(q.begin(),q.end(),comp);
        for (int i = 0; i < aux; ++i)
        {
            if (i % 2 == 0)
                cout << "Row " << ++cases << endl;
            cout << q[i].name2<< endl;
        }
        cout<<endl;
    }
}
