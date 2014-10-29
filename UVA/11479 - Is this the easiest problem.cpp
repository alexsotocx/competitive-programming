#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        long int a,b,c;
        scanf("%ld %ld %ld",&a,&b,&c);
        if(a<b+c && c<b+a && b<a+c)
        {
            if(a==b && b == c)
                printf("Case %d: Equilateral\n",i);
            else if(a==b || b==c || a==c)
                printf("Case %d: Isosceles\n",i);
            else
                printf("Case %d: Scalene\n",i);
        }else
            printf("Case %d: Invalid\n",i);
    }
    return 0;
}
