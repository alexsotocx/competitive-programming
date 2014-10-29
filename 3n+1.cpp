#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
vector<int>seq(100000000,-1);

int sequence(int n)
{
    int ciclo=-1,aux=0,key=n;
    while(true)
    {
        if(n<100000000)
        {
            if(seq[n]!=-1){
                ciclo= seq[n]+aux;
                break;
            }
            else
                aux++,n=(n%2==0)?n/2:3*n+1;
        }
        else
            aux++,n=(n%2==0)?n/2:3*n+1;
    }
    seq[key] = ciclo;
    return ciclo;

}
int main()
{
    seq[1] =1;
    //freopen("in.txt","r",stdin);
    int i,j;
    while(scanf("%d%d",&i,&j)==2)
    {
        int countmax=0;
        int a=min(i,j),b=max(j,i);
        for(int k = a; k<=b; k++)
            countmax =(countmax<sequence(k))?seq[k]:countmax;
        printf("%d %d %d\n",i,j,countmax);

    }
    return 0;
}
