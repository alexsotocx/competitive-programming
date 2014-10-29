#include<stdio.h>
#include<math.h>
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b))
    {
        if(!a && !b)
            break;
        int square=0;
        for (long long i=a;i<=b;i++)
        {
           if(sqrt(i)== floor(sqrt(i)))
                ++square;
        }
        printf("%d\n",square);
    }
    return 0;
}
