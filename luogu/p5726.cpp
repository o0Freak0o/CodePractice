#include<bits/stdc++.h>
using namespace std;

int marks[1001];
int num;
int max_mark = 0;
int min_mark = 11;
int sum;

int main(){
    memset(marks,0,sizeof(marks));
    cin>>num;
    for (int i = 0 ; i < num ; i++){
        cin>>marks[i+1];
        if (marks[i+1] > max_mark)
            max_mark = marks[i+1];
        if (marks[i+1] < min_mark)
            min_mark = marks[i+1];
    }
    for (int i = 1 ; i <= num ; i++)
        sum += marks[i];
    sum -= min_mark;
    sum -= max_mark;
    float result;
    result = float(sum) / (num-2);
    printf("%4.2f",result);
    return 0;
}