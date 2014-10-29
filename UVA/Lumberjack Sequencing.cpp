#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
bool is_sortedasc(const vector<int>& k)
{
    //bool ret = true;
    for(int i=0;i<9;i++)
        if(k[i]>k[i+1])
            return false;
    return true;
}
bool is_sorteddesc(const vector<int>& k)
{
    //bool ret = true;
    for(int i=0;i<9;i++)
        if(k[i]<k[i+1])
            return false;
    return true;
}
int main()
{
    int n;
    printf("Lumberjacks:\n");
    scanf("%d",&n);
    while(n--)
    {
        vector<int>k(10,0);
        for(int i=0;i<10;i++)
            scanf("%d",&k[i]);
        if(is_sortedasc(k) || is_sorteddesc(k))
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }
    return 0;
}
