#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;
vector<bool>v(1000000,true);
void isprime(int n)
{

	v[0]=false;
	v[1]=false;
	int m=sqrt(n);
	for (int i=2; i<=m; i++)
      if (v[i])
         for (int k=i*i; k<=n; k+=i)
            v[k]=false;

}
int main()
{
   int n;
   //freopen("in.txt","r",stdin);
   isprime(1000000);
   while(scanf("%d",&n)==1 && n)
   {
      int i;
      for(i = n-2; i>=n/2; i--)
      {
         if(v[i] && v[n-i])
         {
            printf("%d:\n%d+%d\n",n,n-i,i);
            break;
         }
      }
      if(i==(n/2)-1)
         printf("%d:\nNO WAY!\n",n);
   }
   return 0;
}
