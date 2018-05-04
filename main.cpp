#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int prim(int n)
{
    if(n==0||n==1)
        return 1;
    else if(n%2==0 && n!=2)
        return 1;
    int lim=(int)sqrt((double)n);
    for(int i=3;i<lim;i++)
    {
        if(n%i==0)
            return 1;
    }
    return 0;
}

int main()
{int n=0,m,cnt_min=1,cnt_max=1,nr;
    cin>>nr;
    int v[nr];
    for(int i=0;i<nr;i++)
    {
        cin>>m;
        if(prim(m)==0)
        {
            v[n]=m;
            n++;
        }
    }
    sort(v,v+n);
    for(int i=1;i<n;i++)
    {
        if(v[i-1]==v[i])
            cnt_min++;
        else
            break;
    }
    for(int i=n;i>0;i++)
    {
        if(v[i]==v[i-1 ])
            cnt_max++;
        else
            break;
    }
    cout<<v[0]<<" "<<v[n]<<" "<<cnt_min<<" "<<cnt_max;
    return 0;
}
