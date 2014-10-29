#include<vector>
#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;

int main()
{
    while(true)
    {
        vector<stack<string> >st(52, stack<string>());
        char y[2];
        if(scanf("%s",&y) && string(y)=="#") break;
        st[0].push(string(y));
        for(int i=1; i<52; i++)
        {
            scanf("%s",&y);
           // cout<<string(y)<<endl;
            st[i].push(string(y));
        }


        for(int i=1; i<st.size(); i++)
        {
            if(i==0)continue;
            if(i>=3 && (st[i].top()[1] == st[i-3].top()[1] || st[i].top()[0] == st[i-3].top()[0]))
            {
                 //cout<<st[i].top()<<" "<<st[i-3].top()<<endl;
                st[i-3].push(st[i].top());
                st[i].pop();
                if(!st[i].size())
                    st.erase(st.begin()+i);
                i=i-4;
            }
            else if(st[i].top()[1] == st[i-1].top()[1] || st[i].top()[0] == st[i-1].top()[0])
            {
                //cout<<st[i].top()<<" "<<st[i-1].top()<<endl;
                st[i-1].push(st[i].top());
                st[i].pop();
                if(!st[i].size()){
                    st.erase(st.begin()+i);

                }
                i=i-2;
            }
        }
         if(st.size()==1)
            printf("1 pile remaining: %d\n",st[0].size());
        else
        {
            printf("%d piles remaining:",st.size());
            for(int i=0; i<st.size(); i++)
                printf("% d",st[i].size());
            printf("\n");

        }


    }
    return 0;
}
