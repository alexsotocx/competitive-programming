#include<list>
#include<vector>
#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
using namespace std;
int prese(char x)
{
    return (x=='+' || x=='-')?1:2;
}
int main()
{
    int n;
    cin>>n;
    getchar();
    getchar();
    while(n--)
    {
        string x;
        stack<char>op;
        string ans="";
        while(getline(cin,x) && x!="")
        {
            if(x[0]-'0'>=0 && x[0]-'0'<=9)
                printf("%c",x[0]);
            else if(x[0]=='(')
                op.push('(');
            else if(x[0]==')')
                while(!op.empty())
                {
                    if(op.top()=='(')
                    {
                        op.pop();
                        break;
                    }
                    printf("%c",op.top());
                    op.pop();
                }
            else
            {
                if(op.empty()) op.push(x[0]);
                else
                {
                    while(1)
                    {
                        if(op.empty() || op.top()=='(') {op.push(x[0]);break;}
                        else
                        {
                            int prec1=prese(x[0]),prec2=prese(op.top());
                            if(prec2 < prec1)
                            {
                                op.push(x[0]);
                                break;
                            }
                            else{
                                printf("%c",op.top());
                                op.pop();
                            }
                        }
                    }
                }
            }
        }
        while(!op.empty())
        {
            printf("%c",op.top());
            op.pop();
        }
        printf("\n");
        if(n) puts("");
    }

    return 0;
}
