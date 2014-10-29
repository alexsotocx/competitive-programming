#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    while(cin>>n && n) cout<<floor(log(n*1.0)/log(2.0))<<endl;
    return 0;
}
