#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[101],f[101][10001]={0};
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)
      for(int j=1;j<=m;++j)
      {
          if(j==a[i])f[i][j]=f[i-1][j]+1;
          if(j>a[i]) f[i][j]=f[i-1][j]+f[i-1][j-a[i]];
          if(j<a[i]) f[i][j]=f[i-1][j];
      }
    cout<<f[n][m];
    return 0;
}