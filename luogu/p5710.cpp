// 一些数字可能拥有以下的性质：

// 性质 1：是偶数；
// 性质 2：大于 4 且不大于 12。
// 小A 喜欢这两个性质同时成立的数字；Uim 喜欢这至少符合其中一种性质的数字；八尾勇喜欢刚好有符合其中一个性质的数字；正妹喜欢不符合这两个性质的数字。

// 输入格式
// 输入一个数字 x(0\le x \le 1000)x(0≤x≤1000)

// 输出格式
// 输出这 4 个人是否喜欢这个数字，如果喜欢则输出1，否则输出0，用空格分隔。

// 输入输出样例
// 12    1 1 0 0

#include<bits/stdc++.h>
using namespace std;

bool is_even(int num){
    if(num % 2 == 0)
    return true;
    else
    return false;
}

bool is_legal(int num){
    if(num > 4 && num <= 12)
    return true;
    else
    return false;
}

int main(){
    int a;
    int smal_a = 0;
    int uim = 0;
    int bawei = 0;
    int zhengmen = 0;
    scanf("%d",&a);
    if(is_even(a) && is_legal(a))
    smal_a = 1;
    if(is_even(a) || is_legal(a))
    uim = 1;
    if((is_even(a) && !is_legal(a)) || (!is_even(a) && is_legal(a)))
    bawei = 1;
    if(!is_even(a) && !is_legal(a))
    zhengmen = 1;
    cout<<smal_a<<" "<<uim<<" "<<bawei<<" "<<zhengmen;
    return 0;
}