#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;


int main()
{
   int a,b;
   while(scanf("%d %d",&a,&b)==2 && a>=0 && b>=0)
      printf("%d\n",(int)min(abs(b-a),100-abs(b-a)));
   return 0;
}
