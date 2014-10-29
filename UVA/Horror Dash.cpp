#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int main()
{
    int cases;
    scanf("%d",&cases);
    for(int i=1;i<=cases;i++)
    {
        int s;
        scanf("%d",&s);
        int maxx=-1;
        for(int j=0;j<s;j++)
        {
            int k;
            scanf("%d",&k);
            maxx=(maxx<k)?k:maxx;
        }
        printf("Case %d: %d\n",i,maxx);
    }
    return 0;
}
