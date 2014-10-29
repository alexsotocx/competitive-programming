#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<stack>
using namespace std;
int store[1003],n;
bool vi[1002];
int main()
{
    bool xd = false;
    while(scanf("%d",&n) && n)
    {
        bool founds = false;
        while(!founds)
        {

            for(int i=0; i<n && !founds; i++)
            {
                scanf("%d",&store[i]);
                if(!store[i]) founds=true;
            }
            if(founds) continue;
            memset(vi,false,sizeof(vi));
            stack<int> r;
            bool ok = true;
            int max=1;
            for(int i=0; i<n && ok; i++)
            {
                if(!vi[store[i]])
                {
                    for(int j=max; j<=store[i]; j++)
                    {
                        if(!vi[j])
                        {
                            r.push(j);
                            vi[j]=true;
                        }
                    }
                    max=r.top();
                    r.pop();
                }
                else if(r.top()==store[i])
                    r.pop();
                else if(r.top() != store[i])
                    ok=false;
            }
            if(ok) printf("Yes\n");
            else printf("No\n");

        }
        printf("\n");

    }
    return 0;
}
