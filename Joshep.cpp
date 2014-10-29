#include<iostream>
#include<cstdio>
#include<map>
#include<bitset>
#include<vector>
using namespace std;
int main()
{
    vector<bool>x;
    int k;
    while(scanf("%d",&k)==1 && k)
    {

        for(int i=k; true; i++)
        {
             x= vector<bool>(2*k,1);
            int s=0;
            int co=1;
            for(int j=0; s!=k  ; j++)
            {
                //cout<<j<<" "<<co<<endl;
                if(j==2*k)
                {
                    j=-1;
                    continue;
                }
                if(!x[j]) continue;
                if(j<k && co==i) break;
                else if(co==i && x[j]) co=1,s++,x[j]=0;
                else if(x[j]) co++;

            }

            if(s==k)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
