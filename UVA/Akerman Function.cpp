#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    long i,limit;
    int count;
    int cases=1;
    while(scanf("%ld%ld",&i,&limit)==2 && (i>0&&limit>0))
    {

        printf("Case %d: A = %d, limit = ",cases++,i);
        count=1;
        for (count=1; i!=1; count++)
        {
            if (i%2!=0)
                i=3*i+1;
            else
                i=i/2;
            if (i>limit) break;
        }
        printf("%d, number of terms = %d\n",limit,count);

    }


    return 0;
}
