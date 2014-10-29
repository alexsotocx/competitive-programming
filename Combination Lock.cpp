#include<stdio.h>
int main()
{
    int d,a,b,c;
    while(scanf("%d %d %d %d",&a,&b,&c,&d)==4)
    {
        if(!a && !b && !c && !d)
            break;
        int ans=120;
        if(a<b)
            ans+=40-(b-a);
        else if(a>b)
            ans+=a-b;
        if(b<c)
            ans+=c-b;
        else if(b>c)
            ans+=40-(b-c);
        if(c<d)
            ans+=40-(d-c);
        else if(c>d)
            ans+=c-d;
        printf("%d\n",ans*9);
    }
}
