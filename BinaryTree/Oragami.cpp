#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/**
 * @brief 
 * �������ṹ��(�����)
 * @param *right ��ָ��
 * @param *left ��ָ��
 * @param data ������
 */
typedef struct Nodes{
    Node *left;
    Node *right;
    int data;
} Node;

void PrintProcess(int i, int N, bool down){
    if(i > N)
        return;
    PrintProcess(i+1,N,true);
    // cout<<down?:"��":"͹";
    if (down == true)
        cout<<"��";
    else
        cout<<"͹";
}

int main(){
    return 0;
}