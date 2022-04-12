#include<bits/stdc++.h>
using namespace std;
int a[10001] = {0};
//初始化数组
void Init(int a[]);
long long n;
int i = 4;
int main(){
    cin>>n;
    // Init(a);
    a[1] = 1;
    a[2] = 2;
    a[3] = 2;
    while (i <= n)
    {
        for(int j = 1; j <= i/2; j++){
            a[i] += a[j];
        }
        a[i] += 1;
        i++;
    }
    cout<<a[n];
    return 0;
}
