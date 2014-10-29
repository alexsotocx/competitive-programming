#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
    unsigned long long x;
    vector <long long> count;
    count.push_back(1);
    for(long long i=3; i<1000000000;i+=2)
        count.push_back(count[i-2] + i);
    printf("%ld",count);
    return 0;
}
