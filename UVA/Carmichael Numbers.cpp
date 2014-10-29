#include<iostream>
#include<set>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
bitset<65001>s;
typedef long long ll;
ll m;
#define all(x) x.begin(),x.end()

int main()
{
    ll p;
    set<ll>car;
    car.insert(561);
    car.insert(1105);
    car.insert(1729);
    car.insert(2465);
    car.insert(2821);
    car.insert(6601);
    car.insert(8911);
    car.insert(10585);
    car.insert(15841);
    car.insert(29341);
    car.insert(41041);
    car.insert(46657);
    car.insert(52633);
    car.insert(62745);
    car.insert(63973);
    while(scanf("%lld",&p) && p)
    {

        if(car.find(p)!=car.end())
            printf("The number %lld is a Carmichael number.\n",p);
        else
            printf("%lld is normal.\n",p);
    }
    return 0;
}
