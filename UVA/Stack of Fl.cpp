#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;
bool comp(int a,int b)
{
    return b<a;
}
int main()
{
    string pal;
    while(getline(cin,pal))
    {
        stringstream ss;
        ss<<pal;
        int aux;
        vector<int>x;
        vector<int>q;
        stringstream ret;
        ret<<pal;
        while(ss>>aux)
        {
            q.push_back(aux);
            x.push_back(aux);
        }
        ret<<"\n";
        sort(x.begin(),x.end());
        vector<int>ans;
        int cont=1;
        for(int i=x.size()-1; i>=1; i--)
        {
            stack<int>aux;
            if(x==q) break;
            int j=0;
            while(q[j]!=x[i])
            {
                int b=q[j++];
                aux.push(b);
            }
            if(aux.size()!=0)
            {
                int b=q[j];
                aux.push(b);
                ans.push_back(x.size()+1-aux.size());
                for(int k=0; k<=j; k++)
                {
                    if(aux.size()==0)break;
                    q[k]= (aux.top());
                    aux.pop();
                }

            }
            if(x==q) break;
            j=0;
            while(q[j]!=q[q.size()-cont])
                aux.push(q[j++]);
            aux.push(q[q.size()-cont]);
            for(int k=0; k<=j; k++)
            {
                if(aux.size()==0)break;
                q[k]= (aux.top());
                aux.pop();
            }
            ans.push_back(cont++);
            if(x==q) break;
        }
        for(int i=0; i<ans.size(); i++)
            ret<<ans[i]<<" ";
        ret<<"0\n";
        printf("%s",ret.str().c_str());
    }
    return 0;
}
