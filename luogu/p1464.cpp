#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;
typedef long long ll;
ll rpt[25][25][25];
ll w(ll a,ll b,ll c)
{
    if(a<=0||b<=0||c<=0) return 1;
    //保存状态
    else if(rpt[a][b][c]!=0) return rpt[a][b][c];
    else if(a>20||b>20||c>20) rpt[a][b][c]=w(20,20,20);
    else if(a<b&&b<c) rpt[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    else rpt[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    return rpt[a][b][c];
}
int main()
{
    ll a,b,c;
    while(scanf("%lld%lld%lld",&a,&b,&c)==3){
        memset(rpt,0,sizeof(rpt));
        if(a==-1&&b==-1&&c==-1) break;
        printf("w(%lld, %lld, %lld) = ",a,b,c);
        if(a>20) a=21;
        if(b>20) b=21;
        if(c>20) c=21;
        printf("%lld\n",w(a,b,c));
    }
    return 0;
}