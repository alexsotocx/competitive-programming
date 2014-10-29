#include <stdio.h>
#include <vector>
#include <algorithm>
#define vi vector <int>
#define all(A) (A).begin(), (A).end()
#define s(A) sort(all(A))
using namespace std;
int main()
{
    int C;
    scanf("%d", &C);
    for(int i=0;i<C;i++)
    {
        int N;
        scanf("%d", &N);
        int s;
        float sum=0;
        vi v;
        for (int j=0;j<N;j++)
        {
            scanf("%d", &s);
            sum+=s;
            v.push_back(s);
        }
        sum/=N;
        s(v);
        int students=0;
        int j=N-1;
        while(v[j--]>sum)
            students++;
        float percent = (float)students*(float)100.0/N;
        printf("%.3f%c\n",percent,'%');



    }
}
