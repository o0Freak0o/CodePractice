// һЩ���ֿ���ӵ�����µ����ʣ�

// ���� 1����ż����
// ���� 2������ 4 �Ҳ����� 12��
// СA ϲ������������ͬʱ���������֣�Uim ϲ�������ٷ�������һ�����ʵ����֣���β��ϲ���պ��з�������һ�����ʵ����֣�����ϲ�����������������ʵ����֡�

// �����ʽ
// ����һ������ x(0\le x \le 1000)x(0��x��1000)

// �����ʽ
// ����� 4 �����Ƿ�ϲ��������֣����ϲ�������1���������0���ÿո�ָ���

// �����������
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