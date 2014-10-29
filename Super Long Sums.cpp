#include<vector>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{

    int n,m;
    scanf("%d",&n);
    int x=0;
    while(n--)
    {
        if(x)
            printf("\n");
        x++;
        string pal;
        getline(cin,pal);
        scanf("%d",&m);
        vector<int> c(m+1,0);
        for(int i=1; i<m+1; i++)
        {
            int a,b,k;
            scanf("%d %d",&a,&b);
            k = a+b;
            if(k>=10)
            {
                int j = i-1;
                c[j]++;
                while (c[j]>=10 && j>=1)
                {
                    c[j--]=0;
                    c[j]++;
                }
            }
            c[i]= k%10;
        }
        if(c[0])
            printf("%d",c[0]);
        for(int i=1;i<m+1;i++)
            printf("%d",c[i]);
                printf("\n");
    }
    return 0;
}
