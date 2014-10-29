#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    int n;
    cin>>n;
    getchar();
    while(n--)
    {
        stack<char>b;
        string s;
        getline(cin,s);
        int i;
        bool xd = false, ok = true;
        for(i=0; i<s.length(); i++)
        {
            if(s[i]==']' || s[i]==')')
            {
                if(!b.empty() &&((s[i]==']' && b.top()=='[') || (s[i]==')' && b.top()=='(')))
                {
                    b.pop();
                    continue;
                }
                printf("No\n");
                ok=false;
                break;

            }
            if(s[i]=='[' || s[i]=='(')
                b.push(s[i]);
        }
        if(b.empty() && i==s.length()) printf("Yes\n");
        else if(!b.empty()  && ok)printf("No\n");
    }
    return 0;
}
