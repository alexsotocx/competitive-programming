#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
long tobinary(string k)
{
    int binary=0;
    int a=k.length();
    int c=a;
    for(int i=0;i<c;i++)
    {
        int aux=a-i-2;
         binary+=(k[i]-'0')*(1<<(aux));
        //cout<<(k[i]-'0')*(2<<a-i-2)<<endl;
        //binary+=*2<<((--a)-1);
    }
    return binary;
}
int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
int main()
{
    int n;
	scanf("%d",&n);
	string a,b;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		int b1 = tobinary(a);
		int b2 = tobinary(b);
		int lol = gcd(b1,b2);
		if(lol==1)
			printf("Pair #%d: Love is not all you need!\n",i);
		else
			printf("Pair #%d: All you need is love!\n",i);
	}
    return 0;
}
