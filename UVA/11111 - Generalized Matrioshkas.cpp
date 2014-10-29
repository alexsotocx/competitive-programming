#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<stack>
#include<cstring>
#include<queue>
#include<sstream>
#include<cmath>
using namespace std;
int main()
{
    string s;
    while(getline(cin,s))
    {
        stringstream ss;
        ss<<s;
        int x;
        stack<int>b;
        bool ok=true;
        while(ss>>x)
        {
            if(x<0)
                b.push(x);
            else
            {
                stack<int>ax;
                long long sum =0;
                bool found = false;
                //cout<<"positivo "<<x<<endl;
                while(!b.empty())
                {
                    //cout<<b.top()<<endl;
                    if(x<b.top() && b.top()>0)
                    {
                        ok=false;
                        break;
                    }
                    if(x>(b.top()) && x!=abs(b.top()) && b.top()>0)
                    {
                        sum+=b.top();
                        b.pop();
                        continue;
                    }
                    if(-b.top() == x)
                    {
                        b.pop();
                        found = true;
                        break;
                    }else
                    {
                        ok = false;
                        break;
                    }
                }
               // cout<<"Iteracion"<<endl;

                if(sum< x && ok && found)
                    b.push(x);
                else
                {
                    printf(":-( Try again.\n");
                    ok=false;
                    break;
                }
            }
        }
        b.pop();
        if(ok && b.empty()) printf(":-) Matrioshka!\n");
        else if (ok && !b.empty()) printf(":-( Try again.\n");
        //else if(!b.empty()  && ok)printf(":-( Try again.\n");
    }
    return 0;
}
