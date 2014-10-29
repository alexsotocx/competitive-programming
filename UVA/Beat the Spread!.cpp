#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<bitset>
#include<cstdio>
#include<cmath>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<sstream>
#include<cstring>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<string> vs;

#define all(A) A.begin(),A.end()
#define s(A) sort(all(A))
#define ub(A,k) upper_bound(all(A),k)
#define lb(A,k) lower_bound(all(A),k)
#define binary(A,k) binary_search(all(A),k)
#define PB push_back
#define sz(X) (int)X.size()
#define forn(i,a,b) for(int i=a;i<b;i++)

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int s,ab;
        scanf("%d %d",&s,&ab);
        if(ab>s)
        {
            printf("impossible\n");
            continue;
        }
        int b,a;
        if((s+ab)%2== 0 && (s-ab)%2==0 && (s+ab)>=0 && (s-ab)>=0)
        {
            b=(s-ab)/2;
            a= (s+ab)/2;
        }
        else
        {
            printf("impossible\n");
            continue;
        }
        printf("%d %d\n",max(a,b),min(a,b));
    }
    return 0;
}

