#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        int sump=0, sumi=0;
        int first;
        int second;
        scanf("%d",&first);
        for(int j=1;j<k;j++)
        {
            scanf("%d",&second);
            if(second>first)
                sump++;
            if(first>second)
                sumi++;
            first=second;

        }
        printf("Case %d: %d %d\n",i,sump,sumi);
    }
    return 0;
}
