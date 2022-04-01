#include<bits/stdc++.h>
using namespace std;
const int MAX_N=10001;
int main(){
    int bucket[MAX_N],n,i,k;
    memset(bucket,0,sizeof(bucket));//ÇÐÎðÍü¼Ç³õÊ¼»¯
    cin>>n;
    for(i=0;i<n;i++){
        cin>>k;
        bucket[k]++;
    }
    for(i=0;i<MAX_N;i++){
        while(bucket[i]>0){
            cout<<i<<" ";
            bucket[i]--;
        }
    }
    return 0;
}