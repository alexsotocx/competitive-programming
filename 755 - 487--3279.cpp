#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
char F[]="0123456789ABCDEFGHIJKLMNOPRSTUVWXY";
char T[]="0123456789222333444555666777888999";

int main()
{

    int n;
   // cout<<T[lower_bound(F,F+24+9,'9')-F]<<endl;
    scanf("%d",&n);

    while(n--)
    {
        map<string,int>ma;
        int m;
        scanf("%d",&m);


        while(m--)
        {
            string s;
            cin>>s;
            int k=0;
            string c(8,'-');
            for(int i=0; i<s.size(); i++){
                if(k==3)k++;
                if(s[i]!='-')
                    c[k++]=T[lower_bound(F,(F+24+9),s[i])-F];
            }
            //cout<<c<<endl;
            ma[c]++;
        }
        int counts =0;
        for(map<string,int>::iterator it=ma.begin();it!=ma.end();it++)
            if(it->second>=2){printf("%s %d\n",it->first.c_str(),it->second);counts++;}
        if(!counts) printf("No duplicates.\n");
        if(n) printf("\n");


    }


}
