#include <bits/stdc++.h>
#define ll long long int
using namespace std;
struct pr{
    ll f,b;
};
int main()
{
    ll t;
    cin >> t;
   
    for(ll _ = 1;_<=t;++_)
    {   
        ll n, p;
        cin >> n >> p;
        ll *skill = new ll[n];
        for(ll i = 0; i < n; i++){
            cin >> skill[i];
        }
        sort(skill,skill+n);
        pr q;
        ll i,j;
        q.f = 0;
        q.b = p-1;
        ll cost = 0;
        ll mincost = INT_MAX;
        for(i=0;i<p;++i)
        {
            cost += skill[q.b]-skill[i];
        }
        mincost=min(cost,mincost);
        for(j=p;j<n;++j)
        {
            cost -= (skill[q.b]-skill[q.f]);
                cost+=(skill[j]-skill[q.b])*(p-1);
            
            q.f++;
            q.b++;
            mincost=min(cost,mincost);
        }
        cout<<"Case #"<<_<<": "<<mincost<<"\n";
    }

    return 0;
}